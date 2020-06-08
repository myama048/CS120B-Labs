/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section: 26
 *	Assignment: Lab #11  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_

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


int main(void) {
    /* Insert DDR and PORT initializations */
	unsigned char x;
	DDRC = 0xFF;	PORTC = 0x00;
	DDRD = 0xFF;	PORTD = 0x00;
	DDRA = 0xF0;	PORTA = 0x0F;

	TimerSet(50);
	TimerOn();
	LCD_init();
    /* Insert your solution below */
    while (1) {

	unsigned char x = GetKeypadKey();
	
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
		default:	output = 0x00;	break;
	}
	while(!TimerFlag){};
	TimerFlag = 0;

	if(output >= 0 && output <= 9){
		LCD_Cursor(1);
		LCD_WriteData('0' + output);
	}
	else if(output == 0x0A){
		LCD_Cursor(1);
		LCD_WriteData('A');
	}
	else if(output == 0x0B){
		LCD_Cursor(1);	
		LCD_WriteData('B');
	}
	else if(output == 0x0C){
		LCD_Cursor(1);
		LCD_WriteData('C');
	}
	else if(output == 0x0D){
		LCD_Cursor(1);
		LCD_WriteData('D');
	}
	else if(output == 0x0E){
		LCD_Cursor(1);
		LCD_WriteData('*');
	}
	else if(output == 0x0F){
		LCD_Cursor(1);
		LCD_WriteData('#');
	}
	else {
		LCD_Cursor(1);
	}
    }
    return 1;
}
