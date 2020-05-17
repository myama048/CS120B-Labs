/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section: 26
 *	Assignment: Lab #8  Exercise #3
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
	//DDRD = 0xFF;	PORTD = 0x00;


	unsigned short x;
	unsigned short y;
	unsigned short z;
	unsigned char tmpB = 0;
	ADC_init();
	const unsigned short MAX = 103;
	const unsigned short MIN = 48;
    /* Insert your solution below */
    while (1) {
	x = ADC;
	y = MAX / 8;
	z = MIN;
	//z = (MAX - MIN) / 8;
	//z = MIN + (MAX/8)
	if(x > z){
		tmpB = 1;
	}
	if(x > (z+y)){
		tmpB = 2|tmpB;
	}
	if(x > (z+2*y)){
		tmpB = 4|tmpB;
	}
	if(x > (z+3*y)){
		tmpB = 8|tmpB;
	}
	if(x > (z+4*y)){
		tmpB = 16|tmpB;
	}
	if(x > (z+5*y)){
		tmpB = 32|tmpB;
	}
	if(x > (z+6*y)){
		tmpB = 64|tmpB;
	}
	if(x > (z+7*y)){
		tmpB = 128|tmpB;
	}

	PORTB = tmpB;
    }
    return 1;
}
