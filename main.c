// ******************************************************************************************* //
//
// File:         lab1p2.c
// Date:         12-30-2014
// Authors:      Garrett Vanhoy
//
// Description: 
// ******************************************************************************************* //

#include <xc.h>
#include <sys/attribs.h>
#include "lcd.h"
#include "timer.h"
#include "config.h"
#include "interrupt.h"
#include "switch.h"


// ******************************************************************************************* //

int main(void)
{
    SYSTEMConfigPerformance(10000000);
    initTimer2();
    
    TRISDbits.TRISD0 = 0;
    
    delayMs(1000);
    
    LATDbits.LATD0 = 1;
    delayMs(1000);
    LATDbits.LATD0 = 0;
   
    initLCD();
    
    LATDbits.LATD0 = 1;
    delayMs(1000);
    LATDbits.LATD0 = 0;
    
    
    
//    testChar();
//    testChar();
    writeSTRG("Please Work.");
    
    
    
    
    //LCDShift();
    
    //moveCursorLCD(1,2);
    
   // enableInterrupts();
    
   // initSW1();          //Initialize the button
    
    while(1)
    {
        
    }
    
    return 0;
}

//void __ISR(_CHANGE_NOTICE_VECTOR, IPL2SRS) _CNInterrupt( void ){
//    IFS1bits.CNDIF = 0;     //Reset change notification flag
//    
//    clearLCD();
//}