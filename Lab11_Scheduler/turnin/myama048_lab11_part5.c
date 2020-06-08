/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section: 26
 *	Assignment: Lab #11  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include <bit.h>
#include <../header/io.h>
#include "io.c"
#include <../header/keypad.h>
//#include <../header/lcd_8bit_task.h>
//#include <../header/queue.h>
#include <../header/scheduler.h>
//#include <../header/send.hex>
//#include <../header/seven_seg.h>
//#include <../header/stack.h>
#include <../header/timer.h>
//#include <../header/usart.h>
#include "simAVRHeader.h"
#endif
enum State{Start} state;
unsigned char output = 0;
unsigned char c = 2;
unsigned char top = 9;		//change
unsigned char bottom = 30;	//change
unsigned char player = 2;


void keypadSM(int kstate){
	unsigned char x = GetKeypadKey();
	switch(kstate){
		case Start:	kstate = Start;
				break;
		default:	kstate = Start;
				break;
	}
	
	switch(x){
		case '\0':	output = 0x1F; 	break;
		case '1':	output = 0x01;	break;
		case '2':	output = 0x02;	break;
		case '3':	output = 0x03;	break;
		case '4':	output = 0x04;	break;
		case '5':	output = 0x05;	break;
		case '6':	output = 0x06;	break;
		case '7':	output = 0x07;	break;
		case '8':	output = 0x08;	break;
		case '9':	output = 0x09;	break;
		case 'A':	output = 0x0A;	break;
		case 'B':	output = 0x0B;	break;
		case 'C':	output = 0x0C;	break;
		case 'D':	output = 0x0D;	break;
		case '*':	output = 0x0E;	break;
		case '0':	output = 0x00;	break;
		case '#':	output = 0x0F;	break;
		default:	output = 0x1B;	break;
	}
	return;
}


enum PlayerStates{p_state1, p_state2} p_state;

void PlayerSM(int p_state){
	
	switch(p_state){
		case p_state1:	p_state = p_state2;
				break;
		case p_state2:	p_state = p_state2;
		default:	break;
	}

	switch(p_state){
		case p_state1:	break;
		case p_state2:	if(output == 0x0E){ // go down
					if(player == 18){
						player = 2;
					}
				}
				else if(output == 0x0F){ // go down
					if(player == 2){
						player = 18;
					}
				}
		default:	break;
	}		
	return;
}

enum ObstaclesStates{o_state1, o_state2} o_state;

void ObstaclesSM(int o_state){
	switch(o_state){
		case o_state1:	o_state = o_state2;
				break;
		case o_state2:	o_state = o_state2;
		default:	break;
	}

	switch(o_state){
		case o_state1:	break;
		case o_state2:	if(top >= 1){
					top--;
				}
				else{
					top = 16;
				}
				if(bottom >= 17){
					bottom--;
				}
				else{
					bottom = 32;
				}	
		default: 	break;			
	}

	return;
}

enum PState{pa_state1,pa_state2,pa_state3} pa_state;
void pause(int pa_state, int output){
	switch(pa_state){
		case pa_state1:	LCD_DisplayString(1,"pause");
				if(output == 1){
					pa_state = pa_state2;
				}
				else{	
					pa_state = pa_state1;
				}
				break;
		case pa_state2:	LCD_DisplayString(1,"hello world");
				if(player == top || player == bottom){
					pa_state = pa_state3;
				}
				else{
					pa_state = pa_state2;
				}
				break;
		case pa_state3:	if(output == 0x01){
					pa_state = pa_state2;
				}
				else{
					pa_state = pa_state3;
				}
		default:	break;
	}
	
	switch(p_state){
		case pa_state1:	break;
		case pa_state2:	ObstaclesSM(o_state); 	//set top and bottom
				PlayerSM(p_state);	//set player
				TimerSet(500);					
				LCD_ClearScreen();
				LCD_Cursor(player);
				LCD_WriteData('_');
				LCD_Cursor(top);
				LCD_WriteData('#');
				LCD_Cursor(bottom);
				LCD_WriteData('#');
				break;
		case pa_state3:	LCD_ClearScreen();
				LCD_DisplayString(1,"Game Over");
				break;
		default:	break;
	}
				
}

int main(void) {
    /* Insert DDR and PORT initializations */
	//unsigned char x;
	DDRC = 0xFF;	PORTC = 0x00;
	DDRD = 0xFF;	PORTD = 0x00;
	DDRA = 0xF0;	PORTA = 0x0F;
	
	/*
	static task task1;
	task *tasks[] = { &task1 };
	const unsigned short numTasks = sizeof(tasks)/sizeof(task*);

	//const char start = -1;

	task1.state = state1;
	task1.period = 50;
	task1.elapsedTime = task1.period;
	//task1.TickFct = &Replace;
	*/

	LCD_init();
	LCD_ClearScreen();
	//LCD_Cursor(1);
	TimerSet(100);
	TimerOn();
	pa_state = pa_state1;
	//unsigned short i;
    /* Insert your solution below */

    while (1) {
	TimerSet(100);
	keypadSM(Start);
	pause(pa_state, output);
	while(!TimerFlag);
	TimerFlag = 0;
    }

    return 1;
}
