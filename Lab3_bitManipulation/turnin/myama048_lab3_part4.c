/*	Author: myama048
 *  Partner(s) Name: 
 *	Lab Section:26
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char upA, lowA, tempB, tempC;
    /* Insert your solution below */
    while (1) {
	upA = PINA & 0xF0;
	lowA = PINA & 0x0F;
	
	tempB = 0x0F & (upA >> 4);
	tempC = 0xF0 & (lowA << 4);

	PORTB = tempB;
	PORTC = tempC;

    }
    return 1;
}
