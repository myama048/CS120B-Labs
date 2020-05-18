/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section:26
 *	Assignment: Lab #9  Exercise #2
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

enum State{Start, OFF, ON, UP, DOWN} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0xFF;	PORTB = 0x00;

	PWM_on();
	double frequency = 0;
	double c4 = 261.63;	double d = 293.66;
	double e = 329.63;	double f = 349.23;
	double g = 392.00;	double a = 440.00;
	double b = 493.88;	double c5 = 523.25;
	unsigned char tmpA;
	state = Start;	
    /* Insert your solution below */
    while (1) {

	tmpA = ~PINA & 0xFF;
	switch(state){
		case Start:	state = OFF;
				break;
		case OFF:	if(tmpA == 1){
					state = ON;
					frequency = c4;
				}
				else{
					state = OFF;
				}
				break;
		case ON:	if(tmpA == 0){
					state = ON;
				}
				else if(tmpA == 1){
					state = OFF;
				}
				else if(tmpA == 2){
					state = DOWN;
				}
				else if(tmpA == 4){
					state = UP;
				}
				else {
					state = ON;
				}
				break;
		case UP:	state = ON;
				break;			
		case DOWN:	state = ON;		
		default:	break;
	}

	switch(state){
		case Start:	break;
		case OFF:	frequency = 0;
				break;
		case ON:	frequency = frequency;
				break;
		case UP:	if(frequency == c4){
					frequency = d;
				}
				else if(frequency == d){
					frequency = e;
				}
				else if(frequency == e){
					frequency = f;
				}
				else if(frequency == f){
					frequency = g;
				}
				else if(frequency == g){
					frequency = a;
				}
				else if(frequency == a){
					frequency = b;
				}
				else if(frequency == b){
					frequency = c5;
				}
				break;
		case DOWN:	if(frequency == c5){
					frequency = b;
				}
				else if(frequency == b){
					frequency = a;
				}
				else if(frequency == a){
					frequency = g;
				}
				else if(frequency == g){
					frequency = f;
				}
				else if(frequency == f){
					frequency = e;
				}
				else if(frequency == e){
					frequency = d;
				}
				else if(frequency == d){
					frequency = c4;
				}
		default:	break;
	}
	
	set_PWM(frequency);
	//PORTB = ;
    }
    return 1;
}
