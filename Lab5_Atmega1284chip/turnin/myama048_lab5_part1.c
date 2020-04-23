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
	DDRA = 0xF0;	PORTA = 0x0F;
	DDRC = 0x7F;	PORTC = 0x80;
	
	unsigned char tempA, tempC;
    /* Insert your solution below */
    while (1) {
	tempA = ~PINA & 0x0F;
	tempC= 0x00;

	unsigned char low = 0;

	if(tempA > 0 && tempA <= 4){
		low = 1;
	}

	if(tempA == 0x01 || tempA == 0x02){
		tempC = tempC | 0x20;
	}
	else if(tempA == 0x03 || tempA == 0x04){
		tempC = tempC | 0x30;
	}
	else if(tempA == 5 || tempA == 6){
		tempC = tempC | 0x38;
	}
	else if(tempA >= 7 && tempA <= 9){
		tempC = tempC | 0x3C;
	}
	else if(tempA >= 10 && tempA <= 12){
		tempC = tempC | 0x3E;
	}
	else if(tempA >= 13 && tempA <= 15){
		tempC = tempC | 0x3F;
	}

	if(low == 1){
		tempC = tempC | 0x40;
	}

	PORTC = tempC;
    }
    return 1;
}
