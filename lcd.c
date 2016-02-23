/*
 * File:   lcd.c
 * Authors:
 *
 * Created on December 31, 2014, 1:39 PM
 */

/* TODO: Make define statements for each pin used in the LCD
 */
#include <xc.h>
#include "lcd.h"
#include "timer.h"

/* The pins that you will use for the lcd control will be
 * LCD_RS      RC4
 * LCD_E       RC2
 * LCD_D4      RE7
 * LCD_D5      RE5
 * LCD_D6      RE3
 * LCD_D7      RE1
 * Use these so that we will be able to test your code for grading and to
 * help you debug your implementation!
 */

#define LCD_D7      LATEbits.LATE1
#define LCD_D6      LATEbits.LATE3
#define LCD_D5      LATEbits.LATE5
#define LCD_D4      LATEbits.LATE7
#define LCD_RS      LATCbits.LATC4
#define LCD_RW      LATCbits.LATC14
#define LCD_E       LATCbits.LATC2

#define TRIS_D7 TRISEbits.TRISE1
#define TRIS_D6 TRISEbits.TRISE3
#define TRIS_D5 TRISEbits.TRISE5
#define TRIS_D4 TRISEbits.TRISE7
#define TRIS_RW TRISCbits.TRISC14
#define TRIS_RS TRISCbits.TRISC4
#define TRIS_E  TRISCbits.TRISC2

/* This function should take in a two-byte word and writes either the lower or upper
 * byte to the last four bits of LATE. Additionally, according to the LCD data sheet
 * It should set LCD_RS and LCD_E with the appropriate values and delays.
 * After these commands are issued, there should be a delay.
 * The command type is a simplification. From the data sheet, the RS is '1'
 * when you are simply writing a character. Otherwise, RS is '0'.
 */
void writeFourBits(unsigned char word, unsigned int commandType, unsigned int delayAfter, unsigned int lower){
    //TODO:
    // set the commandType (RS value)
    LATEbits.LATE0 = word&0x01;
    LATEbits.LATE2 = word&0x02;
    LATEbits.LATE4 = word&0x04;
    LATEbits.LATE6 = word&0x08;
    
    //enable
    //delay
    //disable
}

/* Using writeFourBits, this function should write the two bytes of a character
 * to the LCD.
 */
void writeLCD(unsigned char word, unsigned int commandType, unsigned int delayAfter){
    //TODO:
}

/* Given a character, write it to the LCD. RS should be set to the appropriate value.
 */
void printCharLCD(char c) {
    //TODO:
    
    LCD_RS = 1;
    
    
    LCD_D7 = 0;
    LCD_D6 = 0;
    LCD_D5 = 1;
    LCD_D4 = 1;
    
    
}
/*Initialize the LCD
 */
void initLCD(void) {
    // Setup D, RS, and E to be outputs (0).

    TRIS_E = 0;
    TRIS_RS = 0;
    TRIS_RW = 0;
    TRIS_D7 = 0;
    TRIS_D6 = 0;
    TRIS_D5 = 0;
    TRIS_D4 = 0;
    
    // Initilization sequence utilizes specific LCD commands before the general configuration
    // commands can be utilized. The first few initilition commands cannot be done using the
    // WriteLCD function. Additionally, the specific sequence and timing is very important.
    
    delayUs(15000);
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_D7 = 0;
    LCD_D6 = 0;
    LCD_D5 = 1;
    LCD_D4 = 1;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);
    
    delayUs(5000);
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);
    
    delayUs(200);
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);

    // Enable 4-bit interface
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_D7 = 0;
    LCD_D6 = 0;
    LCD_D5 = 1;
    LCD_D4 = 0;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);

    // Function Set (specifies data width, lines, and font.
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_D7 = 1;
    LCD_D6 = 0;
    LCD_D5 = 0;
    LCD_D4 = 0;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_D7 = 0;
    LCD_D6 = 0;
    LCD_D5 = 0;
    LCD_D4 = 0;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_D7 = 1;
    LCD_D6 = 0;
    LCD_D5 = 0;
    LCD_D4 = 0;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_D7 = 0;
    LCD_D6 = 0;
    LCD_D5 = 0;
    LCD_D4 = 0;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_D7 = 0;
    LCD_D6 = 0;
    LCD_D5 = 0;
    LCD_D4 = 1;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_D7 = 0;
    LCD_D6 = 0;
    LCD_D5 = 0;
    LCD_D4 = 0;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_D7 = 0;
    LCD_D6 = 1;
    LCD_D5 = 0;
    LCD_D4 = 0;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(10);
    
    delayUs(100);
    
    
    //End of initializations
    
    
        //Turn on the display
    
        LCD_RS = 0;
        LCD_RW = 0;
        LCD_D7 = 0;
        LCD_D6 = 0;
        LCD_D5 = 0;
        LCD_D4 = 0;

        LCD_E = 1;
        delayUs(1);
        LCD_E = 0;
        delayUs(50);

        LCD_RS = 0;
        LCD_RW = 0;
        LCD_D7 = 1;
        LCD_D6 = 1;
        LCD_D5 = 1;
        LCD_D4 = 1;

        LCD_E = 1;
        delayUs(1);
        LCD_E = 0;
        delayUs(10);

        delayUs(100);
    
   //Clear the display
    
        LCD_RS = 0;
        LCD_RW = 0;
        LCD_D7 = 0;
        LCD_D6 = 0;
        LCD_D5 = 0;
        LCD_D4 = 0;

        LCD_E = 1;
        delayUs(1);
        LCD_E = 0;
        delayUs(2000);

        LCD_RS = 0;
        LCD_RW = 0;
        LCD_D7 = 0;
        LCD_D6 = 0;
        LCD_D5 = 0;
        LCD_D4 = 1;

        LCD_E = 1;
        delayUs(1);
        LCD_E = 0;
        delayUs(10);

        delayUs(2000);
        
        delayMs(100);
         
    
    // 4-bit mode initialization is complete. We can now configure the various LCD
    // options to control how the LCD will function.

    // TODO: Display On/Off Control
        // Turn Display (D) Off
    // TODO: Clear Display (The delay is not specified in the data sheet at this point. You really need to have the clear display delay here.
    // TODO: Entry Mode Set
        // Set Increment Display, No Shift (i.e. cursor move)
    // TODO: Display On/Off Control
        // Turn Display (D) On, Cursor (C) Off, and Blink(B) Off
}

/*
 * You can use printCharLCD here. Note that every time you write a character
 * the cursor increments its position automatically.
 * Since a string is just a character array, try to be clever with your use of pointers.
 */
void printStringLCD(const char* s) {
    //TODO:
}

/*
 * Clear the display.
 */
void clearLCD(){
//    
//        //Clear the display
//    
//        LCD_RS = 0;
//        LCD_RW = 0;
//        LCD_D7 = 0;
//        LCD_D6 = 0;
//        LCD_D5 = 0;
//        LCD_D4 = 0;
//
//        LCD_E = 1;
//        delayUs(1);
//        LCD_E = 0;
//        delayUs(2000);
//
//       
//        LCD_D7 = 0;
//        LCD_D6 = 0;
//        LCD_D5 = 0;
//        LCD_D4 = 1;
//
//        LCD_E = 1;
//        delayUs(1);
//        LCD_E = 0;
//        delayUs(10);
//
//        delayUs(2000);
    
}

void testChar(){
    
    //Testing to print character "I"
    //  UB: 0100
    //  LB: 1001
    
    LCD_RS = 1;
    LCD_RW = 0;
    
    LCD_D7 = 0;
    LCD_D6 = 1;
    LCD_D5 = 0;
    LCD_D4 = 0;

    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(50);

    LCD_D7 = 1;
    LCD_D6 = 1;
    LCD_D5 = 1;
    LCD_D4 = 0;

    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(50);
    
    LCD_RS = 0;

}

void testString(){
    
    //Testing to print String "Ivan"
    //"I" UB: 0100 | LB: 1001
    //"v" UB: 0111 | LB: 0110
    //"a" UB: 0110 | LB: 0001
    //"n" UB: 0110 | LB: 1110
    
    //Print character "I"
    LCD_RS = 1;
    LCD_RW = 0;
    
    LCD_D7 = 0;
    LCD_D6 = 1;
    LCD_D5 = 0;
    LCD_D4 = 0;

    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(50);

    LCD_D7 = 1;
    LCD_D6 = 0;
    LCD_D5 = 0;
    LCD_D4 = 1;

    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(1000);
    
    LCD_RS = 0;
    
    //Print character "v"
    LCD_RS = 1;
    LCD_RW = 0;
    
    LCD_D7 = 0;
    LCD_D6 = 1;
    LCD_D5 = 1;
    LCD_D4 = 1;

    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(50);

    LCD_D7 = 0;
    LCD_D6 = 1;
    LCD_D5 = 1;
    LCD_D4 = 0;

    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(1000);
    
    LCD_RS = 0;
    
    //Print character "a"
    LCD_RS = 1;
    LCD_RW = 0;
    
    LCD_D7 = 0;
    LCD_D6 = 1;
    LCD_D5 = 1;
    LCD_D4 = 0;

    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(50);

    LCD_D7 = 0;
    LCD_D6 = 0;
    LCD_D5 = 0;
    LCD_D4 = 1;

    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(1000);
    
    LCD_RS = 0;
    
    //Print character "n"
    LCD_RS = 1;
    LCD_RW = 0;
    
    LCD_D7 = 0;
    LCD_D6 = 1;
    LCD_D5 = 1;
    LCD_D4 = 0;

    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(50);

    LCD_D7 = 1;
    LCD_D6 = 1;
    LCD_D5 = 1;
    LCD_D4 = 0;

    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(1000);
    
    LCD_RS = 0;
}

void writeLCD_4bit(unsigned char input) {
    unsigned short temp = 0x0000;
    temp |= (input >> 6);
    temp |= ((input << 1) >> 6) << 3;
    temp |= ((input << 2) >> 6) << 5;
    temp |= ((input << 3) >> 6) << 7;
    PORTE = temp;
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(1);
}

/*
 Use the command for changing the DD RAM address to put the cursor somewhere.
 */
void moveCursorLCD(unsigned char x, unsigned char y){
    unsigned char temp = 0x00;
    if(y = 2) temp |= 0x40;
    else temp |= 0x00;
    temp |= x;
    LCD_RS = 0;
    LCD_RW = 0;
    writeLCD_4bit(temp);
    delayUs(50);
    writeLCD_4bit(temp << 4);
    delayUs(50);
}

void writeCHAR(unsigned char c) {
    
    LCD_RS = 1;
    LCD_RW = 0;
    
    char q = c;
    c = c >> 4;
    
    short temp = 0;
    LCD_D4 = (c&0x01);
    LCD_D5 = (c&0x02) >> 1;
    LCD_D6 = (c&0x04) >> 2;
    LCD_D7 = (c&0x08) >> 3;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(50);
    
    c = q;
       
    LCD_D4 = (c&0x01);
    LCD_D5 = (c&0x02) >> 1;
    LCD_D6 = (c&0x04) >> 2;
    LCD_D7 = (c&0x08) >> 3;
    
    LCD_E = 1;
    delayUs(1);
    LCD_E = 0;
    delayUs(1000);
    
    LCD_RS = 0;
}
void writeSTRG(char* a) {
    int i;
    for(i = 0; i < 12; i++) {
        writeCHAR(a[i]);
    }
}

/*
 * This function is called in lab1p2.c for testing purposes.
 * If everything is working properly, you should get this to look like the video on D2L
 * However, it is suggested that you test more than just this one function.
 */
void testLCD(){
    initLCD();
    int i = 0;
    printCharLCD('c');
    for(i = 0; i < 1000; i++) delayUs(1000);
    clearLCD();
    printStringLCD("Hello!");
    moveCursorLCD(1, 2);
    for(i = 0; i < 1000; i++) delayUs(1000);
    printStringLCD("Hello!");
    for(i = 0; i < 1000; i++) delayUs(1000);
}

void LCDShift(void) {
    char a = 'a';
        LCD_RS = 0;
        LCD_RW = 0;
        LCD_D7 = 1;
        LCD_D6 = 0;
        LCD_D5 = 0;
        LCD_D4 = 0;

        LCD_E = 1;
        delayUs(1);
        LCD_E = 0;
        delayUs(10);
        
        LCD_RS = 0;
        LCD_RW = 0;
        LCD_D7 = 0;
        LCD_D6 = 0;
        LCD_D5 = 0;
        LCD_D4 = 1;

        LCD_E = 1;
        delayUs(1);
        LCD_E = 0;
        delayUs(10);
        
        delayUs(100);
        
        LCD_RS = 1;
        LCD_RW = 0;       
        LCD_D7 = 0;
        LCD_D6 = 1;
        LCD_D5 = 0;
        LCD_D4 = 0;
        
        delayUs(1);
        
        LCD_E = 1;
        delayUs(1);
        LCD_E = 0;
        delayUs(50);        
        
        LCD_D7 = 0;
        LCD_D6 = 0;
        LCD_D5 = 0;
        LCD_D4 = 1;

        delayUs(1);
        
        LCD_E = 1;
        delayUs(1);
        LCD_E = 0;
        delayUs(50);  
        
        delayUs(100);
}