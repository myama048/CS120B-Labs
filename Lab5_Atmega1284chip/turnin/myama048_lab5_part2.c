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

enum State{Start, Wait, IncPress, IncRel, DecPress, DecRel, ResetPress, ResetRel} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0xF0;	PORTA = 0x0F;
	DDRC = 0x7F;	PORTC = 0x80;
	
	unsigned char tempA, tempC = 0;
	state = Start;
    /* Insert your solution below */
    while (1) {

	tempA = ~PINA & 0x0F;
	//tempA = PINA;

	
	switch(state){
		case Start:	state = Wait;
				break;
		case Wait:	if(tempA == 1 && tempC < 9){
					state = IncPress;
				}
				else if(tempA == 0x02 && tempC > 0){
					state = DecPress;
				}
				else if(tempA == 3){
					state = ResetPress;
				}
				else {
					state = Wait;
				}
				break;
		case IncPress:	state = IncRel;
				break;
		case IncRel:	if(tempA == 0){
					state = Wait;
				}
				else if(tempA == 3){
					state = ResetPress;
				}
				else {
					state = IncRel;
				}
				break;
		case DecPress:	state = DecRel;
				break;
		case DecRel:	if(tempA == 0){
					state = Wait;
				}
				else if(tempA == 3){
					state = ResetPress;
				}
				else {
					state = DecRel;
				}
				break;
		case ResetPress:	state = ResetRel;
				break;
		case ResetRel:	if(tempA == 0){
					state = Wait;
				}
				else {
					state = ResetRel;
				}
		default:	break;
	}

	switch(state){
		case Start:	tempC = 0;
				break;
		case Wait:	break;
		case IncPress:	tempC++;
				break;
		case IncRel:	break;
		case DecPress:	tempC--;
				break;
		case DecRel:	break;
		case ResetPress:	tempC = 0;
				break;
		case ResetRel:	break;
		default:	break;
	}

	PORTC = tempC;
    }
    return 1;
}
