/*	Author: lab
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char upperNibbleA = 0x00;
    unsigned char lowerNibbleA = 0x00;
    unsigned char lowerB = 0x00;
    unsigned char upperC =0x00;

   
    /* Insert your solution below */
    while (1) {
       upperNibbleA = PINA & 0xF0;
       lowerNibbleA = PINA & 0x0F;
       
       lowerB = upperNibbleA;
       upperC = lowerNibbleA;

       PORTB = lowerB >> 4;
       PORTC = upperC << 4;

       
    }
    return 1;
}
