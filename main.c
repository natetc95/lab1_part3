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

#define CLR 0x01

#define RUN_LED LATDbits.LATD2
#define STP_LED LATDbits.LATD0
#define RUN TRISDbits.TRISD2
#define STP TRISDbits.TRISD0

#define SWT_T TRISDbits.TRISD5
#define SWT PORTDbits.RD5

#define RST_T TRISDbits.TRISD6
#define RST PORTDbits.RD6


// ******************************************************************************************* //

typedef enum RS_enum {
    run, stop, reset
}status;

volatile status state = stop;
volatile status next = run;

int main(void)
{
    enableInterrupts();
    
    SYSTEMConfigPerformance(10000000);
    STP = 0;
    RUN = 0;

    LATDbits.LATD0 = 1;
    initTimer2();
    initLCD();
    initSW();
    delayMs(1000);
    LATDbits.LATD0 = 0;

    writeCMD(CLR);
    int i1, i2, i3, i4, i5, i6;
    printStringLCD("00:00:00");
    
    moveCursorLCD(12,1);
    printStringLCD("STOP");
    
    int f1 = 0;
    int f2 = 0;
    int s1 = 0;
    int s2 = 0;
    int m1 = 0;
    int m2 = 0;
    
    while(1)
    {    
        switch(state) {
            case(reset):
                RUN_LED = 1;
                STP_LED = 1;
                m2 = 0;
                m1 = 0;
                s2 = 0;
                s1 = 0;
                f2 = 0;
                f1 = 0;
                moveCursorLCD(0,1);
                printStringLCD("00:00:00   RESET");
                delayMs(500);
                state = stop;
            case(run):
                RUN_LED = 1;
                STP_LED = 0;
                next = stop;
                delayMs(7);
                f1++;
                if (f1 == 10) {
                    f1 = 0;
                    f2++;
                    if(f2 == 10) {
                        f2 = 0;
                        s1++;
                        if(s1 == 10) {
                            s1 = 0;
                            s2++;
                            if (s2 == 6) {
                                s2 = 0;
                                m1++;
                                if(m1 == 10) {
                                    m1 = 0;
                                    m2++;
                                    if(m2 == 10) {
                                        m2 = 0;
                                        m1 = 0;
                                        s2 = 0;
                                        s1 = 0;
                                        f2 = 0;
                                        f1 = 0;
                                    }
                                    moveCursorLCD(0,1);
                                    printCharLCD(m2 + '0');
                                }
                                moveCursorLCD(1,1);
                                printCharLCD(m1 + '0');
                            }
                            moveCursorLCD(3,1);
                            printCharLCD(s2 + '0');
                        }
                        moveCursorLCD(4,1);
                        printCharLCD(s1 + '0');
                    }
                    moveCursorLCD(6,1);
                    printCharLCD(f2 + '0');
                }
                moveCursorLCD(7,1);
                printCharLCD(f1 + '0');
                moveCursorLCD(11,1);
                printStringLCD("  RUN");
                break;
            case(stop):
                RUN_LED = 0;
                STP_LED = 1;
                next = run;
                moveCursorLCD(11,1);
                printStringLCD(" STOP");
                break;
                
        }
    }
    return 0;
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNInterrupt( void ){
    IFS1bits.CNDIF = 0;     //Reset change notification flag
    CNCONDbits.ON = 0;
        delayMs(1);
        CNCONDbits.ON = 1;
    if(SWT == 0) {
        state = next;
    }
    else if(RST == 0 && state == stop) {
        state = reset;
    }
}