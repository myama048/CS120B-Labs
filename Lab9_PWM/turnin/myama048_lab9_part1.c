/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section:26
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

enum State{Start, Silent, C,D,E} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0xFF;	PORTB = 0x00;

	PWM_on();
	double frequency = 0;
	double c = 261.63;
	double d = 293.66;
	double e = 329.63;
	unsigned char tmpA;
	state = Start;	
    /* Insert your solution below */
    while (1) {

	tmpA = ~PINA & 0xFF;
	switch(state){
		case Start:	state = Silent;
				break;
		case Silent:	if(tmpA == 1){
					state = C;
				}
				else if(tmpA == 2){
					state = D;
				}
				else if(tmpA == 4){
					state = E;
				}
				else {
					state = Silent;
				}
				break;
		case C:		if(tmpA == 1){
					state = C;
				}
				else{
					state = Silent;
				}
				break;
		case D:		if(tmpA == 2){
					state = D;
				}
				else{
					state = Silent;
				}
				break;
		case E:		if(tmpA == 4){
					state = E;
				}
				else {
					state = Silent;
				}
				break;
		default:	break;
	}

	switch(state){
		case Start:	break;
		case Silent:	frequency = 0;
				break;
		case C:		frequency = c;
				break;
		case D:		frequency = d;
				break;
		case E:		frequency = e;
		default:	break;
	}
	
	set_PWM(frequency);
	//PORTB = ;
    }
    return 1;
}
