/*	Author: myama048
 *  Partner(s) Name: 
 *	Lab Section:26
 *	Assignment: Lab #2  Exercise #1
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
	
	unsigned char tempA, tempB;
    /* Insert your solution below */
    while (1) {
	tempA = PINA & 0x03;
	tempB = 0x00;
	if(tempA == 0x01){
		tempB = tempB | 0x01;

	}
	PORTB = tempB;

    }
    return 1;
}
