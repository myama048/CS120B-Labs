/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section:26
 *	Assignment: Lab #6  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include "timer.h" // added
#endif

enum State{Start, ON, PRESS} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0xFF;	PORTB = 0x00;
	TimerSet(300);
	TimerOn();
	unsigned char tmpA, tmpB = 1;
	unsigned char i = 1;
	state = Start;
    /* Insert your solution below */
    while (1) {
	while(!TimerFlag);
	TimerFlag = 0;
	tmpA = ~PINA & 0x0F;

	switch(state){
		case Start:	state = ON;
				break;
		case ON:	if(tmpA == 1){
					state = PRESS;
				}
				else {
					state = ON;
				}
				break;
		case PRESS:	if(tmpA == 1){
					state = ON;
					i = 1;
				}
				else{
					state = PRESS;
				}
				break;
		default:	break;
	}

	switch(state){
		case Start:	break;
		case ON:	if(i == 1){
					tmpB = 1;
				}
				else if(i == 2){
					tmpB = 2;
				}
				else if(i == 3){
					tmpB = 4;
				}
				else if(i == 4){
					tmpB = 2;
				}
				else if(i == 5){
					tmpB = 1;
					i = 1;
				}
				i++;
				break;
		case PRESS:	tmpB = tmpB;
				break;
		default:	break;
	}

	PORTB = tmpB;
    }
    return 1;
}
