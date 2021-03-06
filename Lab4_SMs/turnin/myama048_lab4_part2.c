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
	//DDRB = 0xFE; PORTB = 0x01;
	DDRC = 0xF8; PORTC = 0x07;

	unsigned char  tempC;
	unsigned char button = 0;
    /* Insert your solution below */
    while (1){
	tempC = PORTC;	
		
	if (button == 0){
		if (PINA == 0x03) {//depressed
			tempC = 0;
			button = 1;
		}
		else if (PINA == 0x01){ //inc
			if (tempC < 9){
				tempC++;
				button = 1;
			}
		}
		else if (PINA == 0x02){
			if (tempC > 0){
				tempC--;
				button = 1;
			}
		}
	}
	else {
		if (PINA == 0){
			button = 0;
		}
	}
	PORTC = tempC;
    }
    return 1;
}
