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

void checkButtonState (uint8_t *pState);

void main ()
{
    
ANSEL = 0; // no analog GPIO
ADCON0 = 0; // ADC and DAC converters off
TRISC3 = 0x00; // set RC3 as output
TRISC2 = 0xFF; // set RC2 as input

pedalStatus pedalState = PEDAL_OFF;
buttonStatus buttonState = BUTTON_RELEASED;
RC3 = LOW;

    while (1)
    {
        if (RC2 == LOW)
        {
            buttonState = BUTTON_PRESSED;
        }
        
        switch(pedalState)
        {
            case PEDAL_OFF:
                if (RC2 == HIGH && buttonState == BUTTON_PRESSED)
                {
                    pedalState = PEDAL_ON;
                    RC3 = HIGH; 
                    buttonState = BUTTON_RELEASED;
                }  
            break;
            case PEDAL_ON:
                if (RC2 == HIGH && buttonState == BUTTON_PRESSED)
                {
                    pedalState = PEDAL_OFF;
                    RC3 = LOW; 
                    buttonState = BUTTON_RELEASED;
                }  
            break;
        }
    }
}

void checkButtonState (uint8_t *pState)
{
        if (RC2 == 0x00) 
        {
            __delay_ms(15); // debounce
            if (RC2 == 0x00)
            {
                __delay_ms(200);
                
                if (RC2 == 1)
                {
                    if (*pState == 1) // pedal is on
                    {
                        *pState = 0; // turn off
                        RC3 = 0x00; // turn led off
                    }

                    else // pedal is off
                    {
                        *pState = 1; // turn on
                        RC3 = 0xFF; // turn led on
                    }
                }
            }
        }
}