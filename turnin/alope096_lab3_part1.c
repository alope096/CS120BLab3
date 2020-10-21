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

    unsigned char maskBit = 0x00;
    unsigned char totalOnes = 0x00;
    unsigned char onesA = 0x00;
    unsigned char onesB = 0x00;
    unsigned int i = 0;

    /* Insert your solution below */
    while (1) {
        onesA = PINA;
        onesB = PINB;
        totalOnes = 0x00;
        maskBit = 0x01;
        
        for(i = 0; i<8; i++){
            if(onesA & maskBit){
                totalOnes = totalOnes + 1;
            }
            if(onesB & maskBit){
                totalOnes = totalOnes + 1;
            }

            maskBit = maskBit * 2;
        }

        PORTC = totalOnes;
    }
    return 1;
}
