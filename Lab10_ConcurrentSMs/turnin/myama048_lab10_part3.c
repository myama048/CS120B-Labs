/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #10  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include "timer.h"
#endif

enum SMthree{Start1,ZERO,ONE,TWO} state1;
enum SMblink{Start2,ON,OFF} state2;
enum SMoutput{A,B} state3;
enum SMspeaker{OFF1,S1,S2} state4;

unsigned char ledThree = 0x00;
unsigned char ledBlink = 0x00;
unsigned char speaker = 0x00;


void threeLEDs(){
	switch(state1){
			case Start1:	state1 = ZERO;
					break;
			case ZERO:	state1 = ONE;
					break;
			case ONE:	state1 = TWO;
					break;
			case TWO:	state1 = ZERO;
			default:	break;
		}		

		switch(state1){
			case Start1:	break;
			case ZERO:	ledThree = 0x01;
					break;
			case ONE:	ledThree = 0x02;
					break;
			case TWO:	ledThree = 0x04;
			default:	break;
	}
}

void blinkingLEDs(){
	switch(state2){
		case Start2:	state2 = OFF;
				break;
		case OFF:	state2 = ON;
				break;
		case ON:	state2 = OFF;
		default:	break;
	}		

	switch(state2){
		case Start2:	break;
		case ON:	ledBlink = 0x08;
				break;
		case OFF:	ledBlink = 0;
		default:	break;
	}
}

void output(){
	switch(state3){
		case A:		state3 = B;
				break;
		case B:		state3 = A;
				break;
		default:	state3 = A;
				break;
	}
	
	switch(state3){
		case A:		PORTB = ledThree | ledBlink | speaker;
				break;
		case B:		PORTB = ledThree | ledBlink | speaker;
		default:	break;
	}
}

void Speaker(unsigned char a){
	switch(state4){
		case OFF1:	if(a == 4){
					state4 = S1;
				}
				else {
					state4 = OFF1;
				}
				break;
		case S1:	if(a != 4){
					state4 = OFF;
				}
				else{
					state4 = S2;
				}
		case S2:	if(a != 4){
					state4 = OFF;
				}
				else{
					state4 = S1;
				}
				break;
		default:	break;
	}
	switch(state4){
		case OFF1:	speaker = 0;
				break;
		case S1:	speaker = 0x08;
				break;
		case S2:	speaker = 0;
		default:	break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0xFF;	PORTB = 0x00;
	TimerOn();
	TimerSet(2);
	unsigned long threeLEDPeriod = 300;
	unsigned long blinkLEDPeriod = 1000;
	unsigned char speakerPeriod = 2;
	unsigned char tmpA = 0;
	
    /* Insert your solution below */
    while (1) {
	tmpA = ~PINA & 0xFF;
	while(!TimerFlag){};
	TimerFlag = 0;

	if(threeLEDPeriod == 300){
		threeLEDs();
		threeLEDPeriod = 0;
	}
	if(blinkLEDPeriod == 1000){
		blinkingLEDs();
		blinkLEDPeriod = 0;
	}
	if(speakerPeriod == 2){
		Speaker(tmpA);
		speakerPeriod = 0;
	}
	output();
	
	threeLEDPeriod += 2;
	blinkLEDPeriod += 2;
	speakerPeriod += 2;
    }
    return 1;
}
