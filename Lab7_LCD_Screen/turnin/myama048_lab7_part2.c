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

enum State{Start, ON, PRESS, RELEASE} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	//DDRB = 0xFF;	PORTB = 0x00;
	DDRC = 0xFF;	PORTC = 0x00;
	DDRD = 0xFF;	PORTD = 0x00;
	TimerSet(300);
	TimerOn();
	LCD_init();
	
	unsigned char tmpA, tmpB = 1;
	unsigned char i = 1;
	unsigned char score = 5;
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
		case PRESS:	if(tmpA == 0){
					state = RELEASE;
					if(i == 3){
						score++;
					}
				}
				else{
					state = PRESS;
				}
				break;
		case RELEASE:	if(tmpA == 1){
					state = ON;
					i = 1;
				}
				else {
					state = RELEASE;
				}
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
		case RELEASE:	tmpB = tmpB;
		default:	break;
	}

	//PORTB = tmpB;
	LCD_Cursor(1);
	LCD_WriteData(score + '0');
    }
    return 1;
}
