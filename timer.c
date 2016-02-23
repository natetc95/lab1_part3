/*
 * File:   timer.c
 * Authors:
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include <xc.h>
#include "timer.h"

void initTimer2(){
    PR2 = 0;
    TMR2 = 0;
    T2CONbits.TCKPS = 0;
    T2CONbits.TCS = 0;
    IEC0bits.T2IE = 1;
    IFS0bits.T2IF = 0;
    IPC2bits.T2IP = 4;
    T2CONbits.ON = 0;
}

void delayUs(unsigned int delay){
    IFS0bits.T2IF = 0;
    TMR2 = 0;
    PR2 = delay;
    T2CONbits.ON = 1;
    while(IFS0bits.T2IF == 0);
    T2CONbits.ON = 0;
}

void delayMs(unsigned int delay){
    for(delay = delay; delay > 0; delay--) {
        delayUs(10000);
    }
}