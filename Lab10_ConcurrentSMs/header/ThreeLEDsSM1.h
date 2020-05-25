//ThreeLEDsSM Part 1
//
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include "timer.h"
#endif

enum State {Start, ZERO, ONE, TWO} state;

void threeLEDs(){
	//------------------------------------
	DDRB = 0xFF;	PORTB = 0x00;
	TimerSet(1000);
	TimerOn();
	//------------------------------------
	while(1){
		while(!TimerFlag);
		TimerFlag = 0;

		switch(state){
			case Start:	state = ZERO;
					break;
			case ZERO:	state = ONE;
					break;
			case ONE:	state = TWO;
					break;
			case TWO:	state = ZERO;
			default:	break;
		}		

		switch(state){
			case Start:	break;
			case ZERO:	PORTB = 0x01;
					break;
			case ONE:	PORTB = 0x02;
					break;
			case TWO:	PORTB = 0x04;
			default:	break;
	}

}
