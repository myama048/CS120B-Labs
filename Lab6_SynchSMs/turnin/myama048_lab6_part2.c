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

enum State{Start, ON, ON_REV} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRC = 0xFF;	PORTC = 0x00;
	TimerSet(300);
	TimerOn();
	unsigned char tmpA;
	unsigned char tmpC = 0x00;
	unsigned char cnt = 0x00;
    /* Insert your solution below */
    while (1) {
	while(!TimerFlag);
	TimerFlag = 0;
	tmpA = ~PINA & 0x01;

	switch(state){
		case Start:	 state = ON;
			  	 break;

		case ON:	 if(cnt == 3){
					 state = ON_REV;
					 cnt = 0;
				 }
				 else {
					 state = ON;
				 }
				 break;
		case ON_REV:	 if(cnt == 3){
					 state = ON;
					 cnt = 0;
				 }
				 else {
					 state = ON_REV;
				 }

		default:	 break;
	}

	switch(state){
		case Start:	 break;
		case ON:	 if(cnt == 0){
					 tmpC = 0x01;
					 if(tmpA == 0){
					 	cnt++;
					 }
				 }
				 else if(cnt == 1){
					 tmpC = 0x02;
					 if(tmpA == 0){
					 	cnt++;
					 }
				 }
				 else {
					 tmpC = 0x04;
					 if(tmpA == 0){
					 	cnt++;
					 }
				 }
				 break;
		case ON_REV:	 if(cnt == 0){
				 	 tmpC = 0x04;
					 if(tmpA == 0){
						 cnt++;
					 }
				 }
				 else if(cnt == 1){
					 tmpC = 0x02;
					 if(tmpA == 0){
						 cnt++;
					 }
				 }
				 else {
					 tmpC = 0x01;
					 if(tmpA == 0){
						 cnt++;
					 }
				 }

		default:	 break;
	}

	PORTC = tmpC;
    }
    return 1;
}
