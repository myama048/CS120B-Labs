/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section: 26
 *	Assignment: Lab #8  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/interrupt.h>
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA = (1<<ADEN) | (1<<ADSC) | (1<<ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0xFF;	PORTB = 0x00;
	DDRD = 0xFF;	PORTD = 0x00;

	unsigned short x;
	unsigned char tmpB, tmpD;
	ADC_init();
    /* Insert your solution below */
    while (1) {
	x = ADC;
	tmpB = (char)x;
	tmpD = (char)(x >> 8);

	PORTB = tmpB;
	PORTD = tmpD;
    }
    return 1;
}
