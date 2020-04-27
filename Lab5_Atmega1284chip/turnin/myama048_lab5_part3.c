/*	Author: lab5
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

// Youtube link: https://www.youtube.com/watch?v=-og4laHmNao
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum State{Start, Wait, PosPress, PosRel, NegPress, NegRel} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0xF0;	PORTA = 0x0F;
	DDRC = 0x7F;	PORTC = 0x80;
	
	unsigned char tempA,  tempC = 0;
	state = Start;
	unsigned char cnt = 0;
	unsigned char flip = 0;
    /* Insert your solution below */
    while (1) {

	tempA = ~PINA & 0x0F;
	//tempA = PINA;

	switch(state){
		case Start:	state = Wait;
				break;
		case Wait:	if(flip == 0 && tempA == 1){
					state = PosPress;
					cnt++;
				}
				else if(flip == 1 && tempA == 1){
					state = NegPress;
					cnt++;
				}
				else {
					state = Wait;
				}
				break;
		case PosPress:	state = PosRel;
				break;
		case PosRel:	if(tempA == 0){
					if(cnt > 7){
						flip = 1;
						cnt = 0;
					}
					state = Wait;
				}
				else {
					state = PosRel;
				}
				break;
		case NegPress:	state = NegRel;
				break;
		case NegRel:	if(tempA == 0){
					if(cnt > 7){
						flip = 0;
						cnt = 0;
					}
					state = Wait;
				}
				else {
					state = NegRel;
				}
				break;
		default:	break;
	}

	switch(state){
		case Start:	tempC = 0;
				break;
		case Wait:	break;
		case PosPress:	tempC = 0x01 << (cnt - 1);
				break;
		case PosRel:	break;
		case NegPress:	tempC = 0x01 << (7 - cnt);
				break;
		case NegRel:	break;
		default:	break;
	}

	PORTC = tempC;
    }
    return 1;
}
