/*
 * can.c
 *
 * Created: 05.10.2016 13:50:46
 *  Author: elsala
 */ 

#include "can.h"
#include "MCP2515.h"

#include <avr/interrupt.h>

uint8_t rx_flag;
struct can_message_t empty_msg = {
	.id = 100,
	.length = 1,
	.data[0] = 0
};

void CAN_init() {
	// Initialize MCP2551
	MCP2515_init();
	// Set normal mode
	MCP2515_bit_modify(MCP_CANCTRL, MODE_MASK, MODE_NORMAL);

	uint8_t value = MCP2515_read_data(MCP_CANSTAT);
	if ((value & MODE_MASK) != MODE_NORMAL) {
		printf("MCP2551 is NOT in normal mode after reset!\n");
		return 1;
	}

	// Enable interrupts for receive and error
	MCP2515_bit_modify(MCP_CANINTE, 0xFF, MCP_RX_INT | MCP_ERRIE);
	
	EICRA	|= (1 << ISC21);
	EIMSK	|= (1 << INT2);
	sei();
}

ISR(INT2_vect) {
	CAN_int_vect();
}

void CAN_int_vect() {
	uint8_t interrupt = MCP2515_read_data(MCP_CANINTF);
	if(interrupt & MCP_ERRIF) {
		CAN_error();
	}
	if(interrupt & MCP_RX0IF) {
		rx_flag = 1;
	}
	MCP2515_bit_modify(MCP_CANINTF, 0xFF, 0);
}

void CAN_message_send(struct can_message_t* msg){
	int data_length = 5 + msg->length;
	uint8_t data[data_length];
	data[0] = msg->id >> 3; // Bit 0 to 2 to TXB0SIDH
	data[1] = msg->id << 5; // Bit 3 to 10 to TXB0SIDL
	// Not using extended ID
	data[2] = 0;
	data[3] = 0;
	// length to TXB0DLC
	data[4] = msg->length;
	// Fill rest of array with message data
	for(int i = 5; i < data_length; i++) {
		data[i] = msg->data[i - 5];
	}
	// Write starting from TXB0SIDH
	MCP2515_write_data(MCP_TXB0SIDH, data, data_length); 
	// Request to send from buffer TX0
	MCP2515_request_to_send(1);
}

struct can_message_t CAN_data_receive() {
	struct can_message_t msg;

	if(rx_flag) {
		msg.id = (MCP2515_read_data(MCP_RXB0SIDH) << 3) | (MCP2515_read_data(MCP_RXB0SIDL) >> 5);
		msg.length = (0x0F) & MCP2515_read_data(MCP_RXB0DLC);
		for(int i = 0; i < msg.length; i++) {
			msg.data[i] = MCP2515_read_data(MCP_RXB0D0 + i);
		}
		rx_flag = 0;
	} else {
		return empty_msg;
	}
	return msg;
}

void CAN_error() {
	uint8_t error = MCP2515_read_data(MCP_EFLG);
	if(error & MCP_TXWAR) {
		printf("(E) can.c: Transmission error\n");
	}
	if(error & MCP_RXWAR) {
		printf("(E) can.c: Receive error\n");
	}
}



