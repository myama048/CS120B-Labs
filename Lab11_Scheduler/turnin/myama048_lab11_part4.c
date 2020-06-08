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

enum Rep{state1, out} r_state;


int Replace(int r_state){
	switch(r_state){
		case state1:	r_state = out;
				break;
		case out:	r_state = out;
				break;
		default:	r_state = state1;
				break;
	}
	switch(r_state){
		case state1:	break;
		case out:	if(output != 0x1F){
					if(output >= 0 && output <= 9){
						LCD_WriteData('0' + output);
					}
					else if(output == 0x0A){
						LCD_WriteData('A');
					}
					else if(output == 0x0B){
						LCD_WriteData('B');
					}
					else if(output == 0x0C){
						LCD_WriteData('C');
					}
					else if(output == 0x0D){
						LCD_WriteData('D');
					}
					else if(output == 0x0E){
						LCD_WriteData('*');
					}
					else if(output == 0x0F){
						LCD_WriteData('#');
					}
					if(c == 17){
						c = 1;
					}
					LCD_Cursor(c);
					c++;
				}
		default:	break;
	}
	return r_state;
}

int main(void) {
    /* Insert DDR and PORT initializations */
	unsigned char x;
	DDRC = 0xFF;	PORTC = 0x00;
	DDRD = 0xFF;	PORTD = 0x00;
	DDRA = 0xF0;	PORTA = 0x0F;
	
	
	static task task1;
	task *tasks[] = { &task1 };
	const unsigned short numTasks = sizeof(tasks)/sizeof(task*);

	//const char start = -1;

	task1.state = state1;
	task1.period = 200;
	task1.elapsedTime = task1.period;
	task1.TickFct = &Replace;

	LCD_init();
	LCD_ClearScreen();
	LCD_DisplayString(1,"Congraturations");
	LCD_Cursor(1);
	TimerSet(50);
	TimerOn();
	unsigned short i;
    /* Insert your solution below */
    while (1) {
	keypadSM(state);
	for(i = 0; i < numTasks; i++){
		if(tasks[i]->elapsedTime == tasks[i]->period){
			tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
			tasks[i]->elapsedTime = 0;
		}
		tasks[i]->elapsedTime += 50;
	}

	keypadSM(Start);
	while(!TimerFlag);
	TimerFlag = 0;
    }
    return 1;
}
