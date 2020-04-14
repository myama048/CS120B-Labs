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
	//DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;
	//DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0x00; PORTD = 0xFF;

	unsigned char tempB, tempD, output, weight;
    /* Insert your solution below */
    while (1) {
	tempB = PINB & 0x01;
	tempD = PIND & 0xFF;
	output = 0;
	weight = 0;

	weight = weight + tempB; // weight = 0 or 1
	weight = weight + (tempD * 2);

	if(weight <= 5){
	}
	else if (weight >= 70){
		output = output | 0x02;
	}
	else {
		output = output | 0x04;
	}
	PORTB = output;	
    }
    return 1;
}
