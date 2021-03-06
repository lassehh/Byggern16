/*
 * joystick.c
 *
 * Created: 14.09.2016 16:22:18
 *  Author: elsala
 */ 

#include "joystick.h"
#include "adc.h"

#include <math.h>
#include <avr/io.h>

uint8_t x_voltage_neutral, y_voltage_neutral;

void JOYSTICK_init(void) {
	ADC_init();
	
	DDRB &= ~(1 << PB0);
	PORTB |= (1 << PB0);
	
	JOYSTICK_calibrate();
}

void JOYSTICK_calibrate() {
		x_voltage_neutral = ADC_read(X_JOYSTICK_CHANNEL);
		y_voltage_neutral = ADC_read(Y_JOYSTICK_CHANNEL);
}

int JOYSTICK_compare(joystick_state_t joystick_a, joystick_state_t joystick_b) {
	int x_cmp = (joystick_a.x == joystick_b.x) && (joystick_a.x_dirn == joystick_b.x_dirn);
	int y_cmp = (joystick_a.y == joystick_b.y) && (joystick_a.y_dirn == joystick_b.y_dirn);
	int click_cmp = joystick_a.click == joystick_b.click;
	return x_cmp && y_cmp && click_cmp;
}

joystick_state_t JOYSTICK_get_state() {
	joystick_state_t state;

	uint8_t x_voltage = ADC_read(X_JOYSTICK_CHANNEL);
	uint8_t y_voltage = ADC_read(Y_JOYSTICK_CHANNEL);
	
	state.x = 2 * 100 * (x_voltage - x_voltage_neutral) / (0xFF - 1);
	state.y = 2 * 100 * (y_voltage - y_voltage_neutral) / (0xFF - 1);
	
	if(state.x > 60) {
		state.x_dirn = RIGHT;
		if(state.x > 100) {
			state.x = 100;
		}
	} else if(state.x < -60) {
		state.x_dirn = LEFT;
		if(state.x < -100) {
			state.x = -100;
		}
	} else {
		state.x_dirn = X_NEUTRAL;
	}
	
	if(state.y > 60) {
		state.y_dirn = UP;
	} else if(state.y < -60) {
		state.y_dirn = DOWN;
	} else {
		state.y_dirn = Y_NEUTRAL;
	}
	
	state.click = (PINB & 1) == 0;
	
	return state;
}