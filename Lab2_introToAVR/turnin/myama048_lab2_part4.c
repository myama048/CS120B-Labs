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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;

	unsigned char tempA, tempB, tempC, tempD;
	unsigned char total;
	
    /* Insert your solution below */
    while (1) {
	tempA = PINA;
	tempB = PINB;
	tempC = PINC;
	tempD = 0x00;
	total = tempA + tempB + tempC;

	if(total > 140){//total weight > 140
		tempD =	0x01;
	}

	if((tempA - tempC) > 80 || (tempC - tempA) > 80){// |tempA - tempC| > 80
		tempD = tempD | 0x02;
	}
	
	tempD = tempD | (total & 0xFC);
	PORTD = tempD;
    }
    return 1;
}
