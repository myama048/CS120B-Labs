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
#include "io.h"
#endif

enum State{Start, Init, Inc, Dec, Reset} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRC = 0xFF;	PORTC = 0x00;
	DDRD = 0xFF;	PORTD = 0x00;
	TimerSet(100);
	TimerOn();
	unsigned char tmpA;
	unsigned char tmpB = 0;
	unsigned char i = 0;
	state = Start;
	LCD_ClearScreen();
    /* Insert your solution below */
    while (1) {
	while(!TimerFlag);
	TimerFlag = 0;
	tmpA = ~PINA & 0x0F;

	switch(state){
		case Start:	state = Init;
				break;
		case Init:	if(tmpA == 0x01){
					state = Inc;
					i = 0;
				}
				else if(tmpA == 0x02){
					state = Dec;
					i = 0;
				}
				else if(tmpA == 0x03){
					state = Reset;
				}
				else {
					state = Init;
				}
				break;
		case Inc:	if(tmpA == 0){
					state = Init;
				}
				else if (tmpA == 3){
					state = Reset;
				}
				else {
					state = Inc;
					i++;
				}
				break;
		case Dec:	if(tmpA == 0){
					state = Init;
				}
				else if(tmpA == 3){
					state = Reset;
				}
				else {
					state = Dec;
					i++;
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
				//tmpB = 0;
				break;
		case Init:	break;
		case Inc:	if(tmpB < 9 && i % 10 == 0){
					tmpB++;
				}
				break;
		case Dec:	if(tmpB > 0 && i % 10 == 0){
					tmpB--;
				}
				break;
		case Reset:	tmpB = 0;
		default:	break;
	}

	//PORTB = tmpB;
	LCD_Cursor(1);
	LCD_WriteData(tmpB + '0');
    }
    return 1;
}
