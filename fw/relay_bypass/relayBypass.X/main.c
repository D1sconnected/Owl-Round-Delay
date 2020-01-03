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
while (1)
{
    //PORTC = 0xFF;
    RC3 = 0xFF;
    __delay_ms(100);
    RC3 = 0x00;
    __delay_ms(100);
}
}