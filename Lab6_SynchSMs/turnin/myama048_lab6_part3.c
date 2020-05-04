/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #6  Exercise #3
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

enum State{Start, Init, Inc, Dec, Reset} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0xFF;	PORTB = 0x00;
	TimerSet(100);
	TimerOn();
	unsigned char tmpA;
	unsigned char tmpB;
    /* Insert your solution below */
    while (1) {
	while(!TimerFlag);
	TimerFlag = 0;
	tmpA = ~PINA & 0x01;

	switch(state){
		case Start:	state = Init;
				break;
		case Init:	if(tmpA == 0x01){
					state = Inc;
				}
				else if(tmpA == 0x02){
					state = Dec;
				}
				else if(tmpA == 0x03){
					state = Reset;
				}
				break;
		case Inc:	if(tmpA == 0){
					state = Init;
				}
				else {
					state = Inc;
				}
				break;
		case Dec:	if(tmpA == 0){
					state = Init;
				}
				else {
					state = Dec;
				}
				break;
		case Reset:	if(tmpA == 0){
					state = Init;
				}
				else {
					state = Reset;
				}		
		default:	break;
	}

	switch(state){
		case Start:	tmpB = 7;
				break;
		case Init:	tmpB = tmpB;
				break;
		case Inc:	if(tmpB < 9){
					tmpB++;
				}
				break;
		case Dec:	if(tmpB > 0){
					tmpB--;
				}
				break;
		case Reset:	tmpB = 0;
		default:	break;
	}

	PORTB = tmpB;
    }
    return 1;
}
