/*
 * main.c
 *
 * Created: 31.08.2016 15:30:26
 *  Author: audunel
 */ 

#include "ATmega162.h"
#include "options.h"
#include "menu.h"
#include "game.h"
#include "highscore.h"
#include "drivers/sram.h"
#include "drivers/joystick.h"
#include "drivers/slider.h"
#include "drivers/uart.h"
#include "drivers/can.h"
#include "drivers/timer.h"
#include "drivers/can.h"
#include "../../../can_protocol.h"

#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

int main(void)
{
	UART_init(MYUBRR);

	JOYSTICK_init();
	SLIDER_init();

	SRAM_init();

	MENU_init();

	CAN_init();

	TIMER_init();

	HIGHSCORE_load_from_EEPROM();
	
	state_t state;

	struct can_message_t send_msg;
	struct can_message_t receive_msg;

	joystick_state_t joystick_state = JOYSTICK_get_state();
	joystick_state_t old_joystick_state = joystick_state;
	
	slider_position_t slider_position = SLIDER_get_position();
	slider_position_t old_slider_position = slider_position;
	
	int use_ultrasound = OPTIONS_use_ultrasound();
	int old_use_ultrasound = use_ultrasound;
	
	while(1) {
		state = OPTIONS_get_state();
		
		joystick_state = JOYSTICK_get_state();
		slider_position = SLIDER_get_position();

		switch(state) {
			
			case INITIAL:
			old_joystick_state = joystick_state;
			old_slider_position = slider_position;
			OPTIONS_set_state(MENU);
			break;
			
			case MENU:
			joystick_state = JOYSTICK_get_state();
			use_ultrasound = OPTIONS_use_ultrasound();
			if(joystick_state.y_dirn != old_joystick_state.y_dirn) {
				switch(joystick_state.y_dirn) {
					case UP:
					MENU_decrease_index();
					break;
					case DOWN:
					MENU_increase_index();
					break;
					case Y_NEUTRAL:
					break;
				}
			}
			if(joystick_state.x_dirn != old_joystick_state.x_dirn) {
				switch(joystick_state.x_dirn) {
					case LEFT:
					MENU_return_to_parent();
					break;
					case RIGHT:
					break;
					case X_NEUTRAL:
					break;
				}
			}
			if(joystick_state.click != old_joystick_state.click) {
				if(joystick_state.click == 1) {
					MENU_perform_action();
				}
			}
			old_joystick_state = joystick_state;
			
			use_ultrasound = OPTIONS_use_ultrasound();
			if(use_ultrasound != old_use_ultrasound) {
				send_msg.id = OPTIONS_MSG_ID;
				send_msg.length = 1;
				send_msg.data[ULTRASOUND_INDEX] = use_ultrasound;
				CAN_message_send(&send_msg);
				old_use_ultrasound = use_ultrasound;
			}
			
			break;
			
			case IN_GAME:
			receive_msg = CAN_message_receive();
		
			if(receive_msg.id == NODE_2_ID) {
				int8_t hit = receive_msg.data[IR_INDEX];
				if(hit) {
					GAME_hit();
				}
			}

			if(JOYSTICK_compare(joystick_state, old_joystick_state) == 0 || SLIDER_compare(slider_position, old_slider_position) == 0) {
				send_msg.id = GAME_MSG_ID;
				send_msg.length = 5;
				// Joystick data
				send_msg.data[X_INDEX]		= joystick_state.x;
				send_msg.data[Y_INDEX]		= joystick_state.y;
				send_msg.data[CLICK_INDEX]	= joystick_state.click;
				// Slider data
				send_msg.data[LEFT_INDEX]	= slider_position.left;
				send_msg.data[RIGHT_INDEX]	= slider_position.right;

				CAN_message_send(&send_msg);

				old_joystick_state = joystick_state;
				old_slider_position = slider_position;
			}
			break;
			
			case SAVE_USER:
			

			default:
			OPTIONS_set_state(INITIAL);
		}
	
		_delay_ms(10);
	}
}