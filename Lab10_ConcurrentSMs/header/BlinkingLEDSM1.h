//ThreeLEDsSM Part 1
//
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include "timer.h"
#endif

enum State {Start,OFF,ON} state;

void blinkinLED(){
	//------------------------------------
	DDRB = 0xFF;	PORTB = 0x00;
	TimerSet(1000);
	TimerOn();
	//------------------------------------
	while(1){
		while(!TimerFlag);
		TimerFlag = 0;

		switch(state){
			case Start:	state = OFF;
					break;
			case OFF:	state = ON;
					break;
			case ON:	state = OFF;
			default:	break;
		}		

		switch(state){
			case Start:	break;
			case ON:	PORTB = 0x08;
					break;
			case OFF:	PORTB = 0;
			default:	break;
	}

}
