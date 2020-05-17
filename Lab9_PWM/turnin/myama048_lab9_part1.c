/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #9  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include "PWM.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0x00;	PORTB = 0xFF;
	DDRD = 0xFF;	PORTD = 0x00;


		
    /* Insert your solution below */
    while (1) {

    }
    return 1;
}
