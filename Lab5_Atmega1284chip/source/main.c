/*	Author: lab5
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum State{s, s0, s1, s2, s3, s4, s5, s6} state;

/*
void Tick(){
	
	switch(state){ // transitions
		case Start:	if(PINA == 1 || PINA == 2){
					state = s0;
				}
				else if(PINA == 3 || PINA == 4){
					state = s1;
				}
				else if(PINA == 5 || PINA == 6){
					state = s2;
				}
				else if(PINA >= 7 && PINA <= 9){
					state = s3;
				}
				else if(PINA >= 10 && PINA <= 12){
					state = s4;
				}
				else if(PINA >= 13 && PINA <= 15){
					state = s5;
				}
				break;
		case s0:	state = s0;
				break;
		case s1:	state = s1;
				break;
		case s2:	state = s2;
				break;
		case s3:	state = s3;
				break;
		case s4:	state = s4;
				break;
		case s5:	state = s5;
		default:	break;	
	}

	switch(state){
		case Start:	PORTC = 0x0F;
				break;
		case s0:	PORTC = 0x60;
				break;
		case s1:	PORTC = 0x70;
				break;
		case s2:	PORTC = 0x38;
				break;
		case s3:	PORTC = 0x33;
				break;
		case s4:	PORTC = 0x3E;
				break;
		case s5:	PORTC = 0x3F;
		default:	break;
	}

}

*/
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRC = 0xFF;	PORTC = 0x00;
	
	state = s;
    /* Insert your solution below */
    while (1) {
	state = s;    
	switch(state){
		case s	:	if(PINA == 0){
					state = s;
					break;
				}
				else if(PINA == 1 || PINA == 2){
					state = s0;
					break;
				}
				else if(PINA == 3 || PINA == 4){
					state = s1;
					break;
				}
				else if(PINA == 5 || PINA == 6){
					state = s2;
					break;
				}
				else if(PINA >= 7 || PINA <= 9){
					state = s3;
					break;
				}
				else if(PINA >= 10 || PINA <= 12){
					state = s4;
					break;
				}
				else if(PINA >= 13 && PINA <= 15){
					state = s5;
					break;
				}
				break;
		case s0:	state = s0;
				break;
		case s1:	state = s1;
				break;
		case s2:	state = s2;
				break;
		case s3:	state = s3;
				break;
		case s4:	state = s4;
				break;
		case s5:	state = s5;
				break;
		default:	break;
	}

	switch(state){
		case s	:	PORTC = 0x00;
				break;
		case s0:	PORTC = 0x60;
				break;
		case s1:	PORTC = 0x70;
				break;
		case s2:	PORTC = 0x38;
				break;
		case s3:	PORTC = 0x3C;
				break;
		case s4:	PORTC = 0x3E;
				break;
		case s5:	PORTC = 0x3F;
				break;
		default:	break;
	}
    }
    return 1;
}
