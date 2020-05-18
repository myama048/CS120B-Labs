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
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0xFF;	PORTB = 0x00;

	PWM_on();
	double frequency = 0;
	unsigned char tmpA;	
    /* Insert your solution below */
    while (1) {
	tmpA = ~PINA & 0xFF;

	if(tmpA == 1){
		frequency = 261.63; //C
	}
	else if(tmpA == 2){
		frequency = 293.66; //D
	}
	else if(tmpA == 4){
		frequency = 329.63; //E
	}
	else {
		//do nothing
	}
	
	set_PWM(frequency);
	//PORTB = ;
    }
    return 1;
}
