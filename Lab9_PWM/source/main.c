/*	Author: Masashi Yamaguchi
 *  Partner(s) Name: 
 *	Lab Section:26
 *	Assignment: Lab #9  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include "PWM.h"
#endif

enum State{Start,Init,C4,D,E,F,G,A,B,C5} state;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0xFF;	PORTB = 0x00;

	PWM_on();
	double frequency = 0;
	const double c4 = 261.63;	const double d = 293.66;
	const double e = 329.63;	const double f = 349.23;
	const double g = 392.00;	const double a = 440.00;
	const double b = 493.88;	const double c5 = 523.25;
	unsigned char tmpA;
	state = Start;	
    /* Insert your solution below */
    while (1) {

	tmpA = ~PINA & 0xFF;
	switch(state){
		case Start:	state = Init;
				break;
		case Init:	if(tmpA == 1){
					state = C4;
					frequency = c4;
				}
				else{
					state = Init;
				}
				break;
		case C4:	if(tmpA == 1){
					state = Init;
				}
				else if(tmpA == 2){
					state = D;
				}
				else {
					state = C4;
				}
				break;
		case D:		if(tmpA == 1){
					state = Init;
				}
				else if(tmpA == 2){
					state = E;
				}
				else if(tmpA == 4){
					state = C4;
				}
				else {
					state = D;
				}
				break;
		case E:		if(tmpA == 1){
					state = Init;
				}
				else if(tmpA == 2){
					state = F;
				}
				else if(tmpA == 4){
					state = D;
				}
				else {
					state = E;
				}
				break;
		case F:		if(tmpA == 1){
					state = Init;
				}
				else if(tmpA == 2){
					state = G;
				}
				else if(tmpA == 4){
					state = E;
				}
				else {
					state = F;
				}
				break;
		case G:		if(tmpA == 1){
					state = Init;
				}
				else if(tmpA == 2){
					state = A;
				}
				else if(tmpA == 4){
					state = F;
				}
				else {
					state = G;
				}
				break;
		case A:		if(tmpA == 1){
					state = Init;
				}
				else if(tmpA == 2){
					state = B;
				}
				else if(tmpA == 4){
					state = G;
				}
				else {
					state = A;
				}
				break;
		case B:		if(tmpA == 1){
					state = Init;
				}
				else if(tmpA == 2){
					state = C5;
				}
				else if(tmpA == 4){
					state = A;
				}
				else {
					state = B;
				}
				break;
		case C5:	if(tmpA == 1){
					state = Init;
				}
				else if(tmpA == 4){
					state = B;
				}
				else {
					state = C5;
				}
				break;		
		default:	break;
	}

	switch(state){
		case Start:	break;
		case Init:	set_PWM(0);
				break;
		case C4:	set_PWM(c4);
				break;
		case D:		set_PWM(d);
				break;
		case E:		set_PWM(e);
				break;
		case F:		set_PWM(f);
				break;
		case G:		set_PWM(g);
				break;
		case A:		set_PWM(a);
				break;
		case B:		set_PWM(b);
				break;
		case C5:	set_PWM(c5);
				break;

		default:	break;
	}
	
	//set_PWM(frequency);
    }
    return 1;
}
