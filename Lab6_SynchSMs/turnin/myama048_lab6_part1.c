/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #6  Exercise #
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

enum State{Start, ON} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRC = 0xFF;	PORTC = 0x00;
	TimerSet(1000);
	TimerOn();
	unsigned char tmpC = 0x00;
	unsigned char cnt = 0x00;
    /* Insert your solution below */
    while (1) {
	while(!TimerFlag);
	TimerFlag = 0;

	switch(state){
		case Start:	 state = ON;
			  	 break;

		case ON:	 state = ON;
				 break;

		default:	 break;
	}

	switch(state){
		case Start:	 break;
		case ON:	 if(cnt == 0){
					 tmpC = 0x01;
					 cnt++;
				 }
				 else if(cnt == 1){
					 tmpC = 0x02;
					 cnt++;
				 }
				 else {
					 tmpC = 0x04;
					 cnt =0;
				 }
				 break;
		default:	 break;
	}

	PORTC = tmpC;
    }
    return 1;
}
