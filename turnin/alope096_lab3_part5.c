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
    DDRB = 0xFE; PORTB = 0x01;
    DDRD = 0x00; PORTD = 0xFF;

    unsigned short weight = 0x00;
    unsigned char airbagEnabled = 0x00;
    unsigned char airbagDisabled = 0x00;

   
    /* Insert your solution below */
    while (1) {
       weight = (PIND << 1) | (PINB & 0x1);
       airbagEnabled = 0x00;
       airbagDisabled = 0x00;

       if(weight >= 70){
         airbagEnabled = 0x02;
       }
       else{
         airbagEnabled = 0x00;
       }

       if((weight > 5) && (weight< 70)){
         airbagDisabled = 0x40;
       }
       else{
         airbagDisabled = 0x00;
       }

       if(weight <5){
         airbagEnabled = 0x00;
         airbagDisabled = 0x00;
       }

       PORTB = airbagEnabled | airbagDisabled;
    }
    return 1;
}
