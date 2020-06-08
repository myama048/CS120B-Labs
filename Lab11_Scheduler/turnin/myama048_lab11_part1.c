/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section: 26
 *	Assignment: Lab #11  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_

//#include <../header/io.h>
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

int keypadSM(int kstate){
	unsigned char x = GetKeypadKey();
	switch(kstate){
		case Start:	kstate = Start;
				break;
		default:	kstate = Start;
				break;
	}
	
	switch(x){
		case '\0':	PORTB = 0x1F; 	break;
		case '1':	PORTB = 0x01;	break;
		case '2':	PORTB = 0x02;	break;
		case '3':	PORTB = 0x03;	break;
		case '4':	PORTB = 0x04;	break;
		case '5':	PORTB = 0x05;	break;
		case '6':	PORTB = 0x06;	break;
		case '7':	PORTB = 0x07;	break;
		case '8':	PORTB = 0x08;	break;
		case '9':	PORTB = 0x09;	break;
		case 'A':	PORTB = 0x0A;	break;
		case 'B':	PORTB = 0x0B;	break;
		case 'C':	PORTB = 0x0C;	break;
		case 'D':	PORTB = 0x0D;	break;
		case '*':	PORTB = 0x0E;	break;
		case '0':	PORTB = 0x00;	break;
		case '#':	PORTB = 0x0F;	break;
		default:	PORTB = 0x1B;	break;
	}
	return kstate;
}

int main(void) {
    /* Insert DDR and PORT initializations */
	unsigned char x;
	DDRC = 0xFF;	PORTC = 0x00;
	DDRA = 0xF0;	PORTA = 0x0F;

	static task task1;
	task *tasks[] = { &task1 };
	const unsigned short numTasks = sizeof(tasks)/sizeof(task*);

	//const char start = -1;

	task1.state = Start;
	task1.period = 50;
	task1.elapsedTime = task1.period;
	task1.TickFct = &keypadSM;

	TimerSet(50);
	TimerOn();
	unsigned short i;
    /* Insert your solution below */
    while (1) {
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
