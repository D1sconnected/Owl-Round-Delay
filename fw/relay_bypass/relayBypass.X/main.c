/* 
 * File:   main.c
 * Author: yupdi
 *
 * Created on 3 ?????? 2020 ?., 15:16
 */

#include <stdio.h>
#include <stdlib.h>

// Supplementary libraries
#include <stdint.h>
#include <xc.h>
// Include configuration bits
#include "header.h"

void main ()
{
    
ANSEL = 0; // no analog GPIO
ADCON0 = 0; // ADC and DAC converters off

TRISC3 = 0x00; // set RC3 as output
TRISC2 = 0xFF; // set RC2 as input
//PORTC = 0x00;

uint8_t state = 0;

RC3 = 0x00;

    while (1)
    {
        if (RC2 == 0x00) 
        {
            __delay_ms(15); // debounce
            if (RC2 == 0x00)
            {
                if (state == 1) // pedal is on
                {
                    state = 0; // turn off
                    RC3 = 0x00; // turn led off
                }

                else // pedal is off
                {
                    state = 1; // turn on
                    RC3 = 0xFF; // turn led on
                }
            }
        }
        __delay_ms(10); 
        /*
        RC3 = 0xFF;
        __delay_ms(100);
        RC3 = 0x00;
        __delay_ms(100);
        */
    }
}