/*	Author: myama048
 *  Partner(s) Name: 
 *	Lab Section:26
 *	Assignment: Lab #3  Exercise #1
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
	//DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tempA, tempC;
    /* Insert your solution below */
    while (1) {
	tempA = PINA & 0xFF;
	tempC = 0x00;
	unsigned char low = 0;
	unsigned char key = PINA & 0x10;
	unsigned char seated = PINA & 0x20;
	unsigned char seatbelt = PINA & 0x40;


	if(PINA <= 4){
		low = 1;
	}		
	
	if(tempA == 0x01 || tempA == 0x02){
		tempC = tempC | 0x20;	
	}
	else if(tempA == 3 || tempA == 4){
		tempC = tempC | 0x30;
	}
	else if(tempA == 5 || tempA == 6){
		tempC = tempC | 0x38;
	}
	else if (tempA >=  7 && tempA <= 9){
		tempC = tempC | 0x3C;
	}
	else if (tempA >= 10 && tempA <=12){
		tempC = tempC | 0x3E;
	}
	else if (tempA >= 13 && tempA <= 15){
		tempC = tempC | 0x3F;
	}

	if(low == 1){
		tempC = tempC | 0x40;	
	}

	if((key == 0x10) && (seated == 0x20) && (seatbelt == 0)) {
		tempC = tempC | 0x80;
	}
	
	PORTC = tempC;

    }
    return 1;
}
