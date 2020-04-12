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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tempA, tempB, cnt;
    /* Insert your solution below */
    while (1) {
	tempA = PINA;
	tempB = PINB;
	cnt = 0;

	if((tempA & 0x01) == 0x01){
		cnt++;
	}
	if((tempA & 0x02) == 0x02){
		cnt++;
	}
	if((tempA & 0x04) == 0x04){
		cnt++;
	}
	if((tempA & 0x08) == 0x08){
		cnt++;
	}
	if((tempA & 0x10) == 0x10){
		cnt++;
	}
	if((tempA & 0x20) == 0x20){
		cnt++;
	}
	if((tempA & 0x40) == 0x40){
		cnt++;
	}
	if((tempA & 0x80) == 0x80){
		cnt++;
	}

	if((tempB & 0x01) == 0x01){
		cnt++;
	}
	if((tempB & 0x02) == 0x02){
		cnt++;
	}
	if((tempB & 0x04) == 0x04){
		cnt++;
	}
	if((tempB & 0x08) == 0x08){
		cnt++;
	}
	if((tempB & 0x10) == 0x10){
		cnt++;
	}
	if((tempB & 0x20) == 0x20){
		cnt++;
	}
	if((tempB & 0x40) == 0x40){
		cnt++;
	}
	if((tempB & 0x80) == 0x80){
		cnt++;
	}

	PORTC = cnt;
	
    }
    return 1;
}
