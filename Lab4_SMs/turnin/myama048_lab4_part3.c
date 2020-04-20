/*	Author: myama048
 *  Partner(s) Name: Masashi Yamaguchi 
 *	Lab Section: 26
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
//#include "RIMS.h"

enum States {Start, s0, s1, s2, s3} state;
//DDRA = 0x00;	PORTA = 0xFF;
//DDRB = 0xFF;	PORTB = 0x00;

 
void Tick(){
	switch(state){//transitions
		case Start:	state = s0;
				break;
		case s0:	if(PINA == 0x04){
					state = s1;
				}
				else {
					state = s0;
				}
				break;
		case s1:	if(PINA == 0x00){
					state = s2;
				}
				else {
					state = s0;
				}
				break;
		case s2:	if (PINA == 0x02){
					state = s3;
				}
				else {
					state = s0;
				}
		case s3:	if (PINA == 0x80){
					state = s0;
				}
				else {
					state = s3;
				}
				break;
		default:	state = s0;
				break;

	}

	switch(state){
		case s0:	PORTB = 0x00;
				break;
		case s1:	PORTB = 0x00;
				break;
		case s2:	PORTB = 0x00;
				break;
		case s3:	PORTB = 0x01;
				break;
		default:	break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	//DDRC = 0xF8; PORTC = 0x07;

	//unsigned char  tempC;
	//unsigned char button = 0;
    /* Insert your solution below */
    while (1){
	Tick();
    }
    return 1;
}
