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

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;

	unsigned char  tempB;
	unsigned char button = 0;
    /* Insert your solution below */
    while (1){

	tempB = PORTB;	// PB0 is initially ON
	
	if (tempB == 0x01){
		if(button == 0){
			if(PINA == 1){
				button = 1;
				tempB = 0x02;
			}
			else {
				button = 0;// stay
			}
		}
		else {
			if(PINA == 0){
				button = 0;
				tempB = 0x01;
			}
			else {
				button = 1;
			}
		}
	}
	else {
		if(button == 1){
			if(PINA == 0){
				button = 0;
			}
			else {
				button = 1;
			}
		}
		else {
			if(PINA == 1){
				button = 1;
				tempB = 0x01;
			}
			else {
				button = 0;
			}
		}
	}
	
	PORTB = tempB;
	
    }
    return 1;
}
