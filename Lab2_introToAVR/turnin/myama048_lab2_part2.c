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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tempA;
	unsigned char cntavail;
    /* Insert your solution below */
    while (1) {
	tempA = PINA & 0x0F;

	if(tempA == 0x00){
		cntavail = 0x04;
	}
	else if(tempA == 0x01 || tempA == 0x02 || tempA == 0x04 || tempA == 0x08){
		cntavail = 0x03;
	}
	else if (tempA == 0x07 || tempA == 0x0B || tempA == 0x0D || tempA == 0x0E){
		cntavail = 0x01;
	}
	else if(tempA == 0x0F){
		cntavail = 0;
	}
	else {
		cntavail = 0x02;
	}

	PORTC = cntavail;
	
    }
    return 1;
}
