/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section:26
 *	Assignment: Lab #6  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
// Demo Video: https://www.youtube.com/watch?v=ak1uOcTAXUI
// this video includes all demos; part 1 - 3
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include "timer.h" // added
#endif

enum State{Start, ON} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFF;	PORTB = 0x00;
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

	PORTB = tmpC;
    }
    return 1;
}
