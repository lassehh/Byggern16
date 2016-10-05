/*
 * CFile1.c
 *
 * Created: 14.09.2016 10:30:16
 *  Author: elsala
 */ 
#include "adc.h"
#include "../byggern.h"

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*ISR(INT0_vect)
{
	printf("Interrupt");
}*/

int ADC_init(void){
	/* Enables external memory interface, and releases PC7-PC4 from external memory. */
	MCUCR |= (1 << SRE);
	SFIOR |= (1 << XMM2);
	/* Set the interrupt pin to input */
	/*DDRD	|= (1 << PD2);
	GICR	|= (1 << INT0);
	MCUCR	|= (1 << ISC01);
	sei();*/
	
	return 0;
}

uint8_t ADC_read(uint8_t chan) {
	volatile uint8_t *ext_adc = (uint8_t *) ADC_DATA;
	*ext_adc = 0x04 | chan;
	_delay_us(40);
	return *ext_adc;
}