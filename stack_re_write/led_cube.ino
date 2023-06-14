// Author  :  Danny Restrepo
// Members :  Bodgan Gula
//         :  Nitin Suryadevara
//         :  Mark Gelman
//         :  Danny Restrepo
// Emails  :  restrepo@pdx.edu
//         :  gula@pdx.edu
//         :  gelman@pdx.edu
//         :  nitin2@pdx.edu
// Course  :  ECE103 Engineering Programming
// School  :  Portland State University
// Date    :  25th May 2023
// Project :  Interactive LED Cube
// Title   :  LED Cube Program Entry, Source File

/*
    Program Description:
        The Interactive LED Cube program, developed by a team of students at Portland State
        University, is designed to control an 8x8x8 RGB LED cube to display various animations.
        The program uses the SPI library to send data to shift registers that control the LEDs.
        The cube's state is updated in an interrupt service routine triggered by a hardware timer.

        The program begins by initializing the SPI bus, setting up the hardware timer, and defining
        the GPIO pins for data, clock, latch, and blank signals. It also initializes arrays to store
        the state of each LED in the cube. Each LED's state is represented by four bytes (one for
        each color component and one for the LED's intensity), and the cube's entire state is stored
        in a series of byte arrays.

        In the main loop, the program waits for user input from a serial interface. Depending on the
        received command, it executes a corresponding animation function. If no command is received,
        it runs a default animation.

        The program also includes a function to set the state of a specific LED. This function takes
        the LED's coordinates and color as arguments, and updates the corresponding bytes in the
        cube's state arrays.

        The timer interrupt service routine, onTimer, is the heart of the program. It is called
        regularly by the hardware timer and updates the cube's display. It does this by sending the
        current state of the cube to the shift registers, which in turn control the LEDs. The
        routine uses Bit Angle Modulation to control the brightness of each LED, and it cycles
        through the cube's levels to multiplex the LEDs.

        The program also includes a series of helper functions to shift out data to the shift
        registers, latch the data to the output, and set the current row, level, color, and
        intensity to be displayed.
*/



/***************************** Includes & Macros ******************************/
#include <SPI.h>                 // SPI Library used to clock data out to the shift registers
#include <Arduino.h>             // For the byte data type
#include "animations.h"          // Function prototypes for animations module
#include "menu.h"                // Function prototypes for menu module

const int latch_pin = 21;        // GPIO21 will drive RCLK (latch) on shift registers
const int blank_pin = 26;        // Same, can use any pin you want for this, just make sure you pull up via a 1k to 5V
const int data_pin = 18;         // Used by SPI, must be GPIO18, used for serially driving the shift register daisy chains
const int clock_pin = 5;         // Used by SPI, must be GPIO5

// These variables are used by multiplexing and Bit Angle Modulation Code
int shift_out;                   // Used in the code a lot in for loops



// This is how the brightness for every LED is stored,  
// Each LED only needs a 'bit' to know if it should be ON or OFF, so 64 Bytes gives you 512 bits= 512 LEDs
// Since we are modulating the LEDs, using 4 bit resolution, each color has 4 arrays containing 64 bits each
byte red0[32], green0[32], blue0[32];
byte red1[32], green1[32], blue1[32];
byte red2[32], green2[32], blue2[32];
byte red3[32], green3[32], blue3[32];



/******************************** Sketch Setup ********************************/
void setup()
{
    pinMode(latchPin_PISO, OUTPUT);
    pinMode(dataPin_PISO, INPUT);  
    pinMode(clockPin_PISO, OUTPUT);

    pinMode(latchPin_SIPO, OUTPUT);
    pinMode(dataPin_SIPO, OUTPUT);  
    pinMode(clockPin_SIPO, OUTPUT);

    Serial.begin(9600);
}



/******************************** Sketch Loop *********************************/
void loop()
{
    // Byte to write to the cathode shift register, 1 of them, shifting the ON level in each byte in the array
    byte cathode;

    int choice = menu_select();

    // Loads in the user choice from the menu module
    switch (choice)
    {
        case 0:
            // Load default
            break;

        case 1:
            sine_wave();
            break;

        case 2:
            rain();
            break;

        case 3:
            folder();
            break;

        case 4:
            wipe_out();
            break;

        case 5:
            bouncy();
            break;

        case 6:
            color_wheel_v2();
            break;

        case 7:
            harlem_shake();
            break;

        case 8:
            clean();
            break;

        case 9:
            // diagnostic_mode();
            break;
    }

    //* For DEBUGGING *//
    // To control an LED:
    // set_led(level you want 0-7, row you want 0-7, column you want 0-7, red brighness 0-15, green brighness 0-15, blue brighness 0-15);
    // set_led(4, 4, 4, 15, 15, 15);
    // delay(500);

    //* For DEBUGGING *//
    // sine_wave();
    // clean();
    // rain();
    // folder();
    // wipe_out();
    // bouncy();
    // color_wheel_v2();
    // clean();
    // harlem_shake();
}



/***************************** LED Update Routine *****************************/
void set_led(int level, int row, int column, byte red, byte green, byte blue)
{
    // This routine is how LEDs are updated, with the inputs for the LED location and its R G and B brightness levels

    // First, check and make sure nothing went beyond the limits, just clamp things at either 0 or 7 for location, and 0 or 15 for brightness
    if (level <= 0)
    {
        level = 0;
    }
    if (level >= 7)
    {
        level = 7;
    }
    if (row <= 0)
    {
        row = 0;
    }
    if (row >= 7)
    {
        row = 7;
    }
    if (column <= 0)
    {
        column = 0;
    }
    if (column >= 7)
    {
        column = 7;
    }
    if (red <= 0)
    {
        red = 0;
    }
    if (red >= 15)
    {
        red = 15;
    }
    if (green <= 0)
    {
        green = 0;
    }
    if (green >= 15)
    {
        green = 15;
    }
    if (blue <= 0)
    {
        blue = 0;
    }
    if (blue >= 15)
    {
        blue = 15;
    }

    // There are 512 LEDs in the cube, so when we write to level 2, column 5, row 4, that needs to be translated into a number from 0 to 511
    int whichbyte = int(((level * 32) + (row * 8) + column) / 8);

    // The first level LEDs are first in the sequence, then 2nd level, then third, and so on
    // The (level*64) is what indexes the level's starting place, so level 0 are LEDs 0-63, level 1 are LEDs 64-127, and so on

    // The column counts left to right 0-7 and the row is back to front 0-7
    // This means that if you had level 0, row 0, the bottom back row would count from 0-7, 

    // So if you looked down on the cube, and only looked at the bottom level
    // 00 01 02 03 04 05 06 07
    // 08 09 10 11 12 13 14 15
    // 16 17 18 19 20 21 22 23
    // 24 25 26 27 28 29 30 31
    // 32 33 34 35 36 37 38 39
    // 40 41 42 43 44 45 46 47  
    // 48 49 50 51 52 53 54 55  
    // 56 57 58 59 60 61 62 63

    // Then,  if you incremented the level, the top right of the grid above would start at 64
    // The reason for doing this, is so you don't have to memorize a number for each LED, allowing you to use level, row, column

    // Now, what about the divide by 8 in there?
    //...well, we have 8 bits per byte, and we have 64 bytes in memory for all 512 bits needed for each LED, so
    // we divide the number we just found by 8, and take the integ7er of it, so we know which byte, that bit is located
    // Confused? that's ok, let's take an example, if we wanted to write to the LED to the last LED in the cube, we would write a 7, 7, 7
    // giving (7*64)+(7*8)=7 = 511, which is right, but now let's divide it by 8, 511/8 = 63.875, and take the int of it so, we get 63,
    // this is the last byte in the array, which is right since this is the last LED

    // This next variable is the same thing as before, but here we don't divide by 8, so we get the LED number 0-511
    int wholebyte = (level * 32) + (row * 8) + column;
    // This will all make sense in a sec

    // This is 4 bit color resolution, so each color contains x4 64 byte arrays, explanation below:
    bitWrite(red0[whichbyte], wholebyte - (8 * whichbyte), bitRead(red, 0));
    bitWrite(red1[whichbyte], wholebyte - (8 * whichbyte), bitRead(red, 1));
    bitWrite(red2[whichbyte], wholebyte - (8 * whichbyte), bitRead(red, 2));
    bitWrite(red3[whichbyte], wholebyte - (8 * whichbyte), bitRead(red, 3));

    bitWrite(green0[whichbyte], wholebyte - (8 * whichbyte), bitRead(green, 0));
    bitWrite(green1[whichbyte], wholebyte - (8 * whichbyte), bitRead(green, 1));
    bitWrite(green2[whichbyte], wholebyte - (8 * whichbyte), bitRead(green, 2));
    bitWrite(green3[whichbyte], wholebyte - (8 * whichbyte), bitRead(green, 3));

    bitWrite(blue0[whichbyte], wholebyte - (8 * whichbyte), bitRead(blue, 0));
    bitWrite(blue1[whichbyte], wholebyte - (8 * whichbyte), bitRead(blue, 1));
    bitWrite(blue2[whichbyte], wholebyte - (8 * whichbyte), bitRead(blue, 2));
    bitWrite(blue3[whichbyte], wholebyte - (8 * whichbyte), bitRead(blue, 3));

    // Are you now more confused? You shouldn't be! It's starting to make sense now. Notice how each line is a bitWrite, which is,
    // bitWrite(the byte you want to write to, the bit of the byte to write, and the 0 or 1 you want to write)
    // This means that the 'whichbyte' is the byte from 0-63 in which the bit corresponding to the LED from 0-511
    // Is making sense now why we did that? Taking a value from 0-511 and converting it to a value from 0-63, since each LED represents a bit in 
    // an array of 64 bytes.
    // Then next line is which bit 'wholebyte-(8*whichbyte)'  
    // This is simply taking the LED's value of 0-511 and subracting it from the BYTE its bit was located in times 8
    // Think about it, byte 63 will contain LEDs from 504 to 511, so if you took 505-(8*63), you get a 1, meaning that,
    // LED number 505 is is located in bit 1 of byte 63 in the array

    // Is that it? No, you still have to do the bitRead of the brightness 0-15 you are trying to write,
    // if you wrote a 15 to RED, all 4 arrays for that LED would have a 1 for that bit, meaning it will be on 100%
    // This is why the four arrays read 0-4 of the value entered in for RED, GREEN, and BLUE
    // hopefully this all makes some sense?
}



/**************************** Bit Angle Modulation ****************************/
void IRAM_ATTR onTimer()
{
    // Turn all of the LEDs OFF, by writing a 1 to the blank pin
    digitalWrite(blank_pin, HIGH);

    // This is 4 bit 'Bit angle Modulation' or BAM, There are 8 levels, so when a '1' is written to the color brightness, 
    // each level will have a chance to light up for 1 cycle, the BAM bit keeps track of which bit we are modulating out of the 4 bits
    // Bam counter is the cycle count, meaning as we light up each level, we increment the bam_counter
    if (bam_counter == 8)
    {
        bam_bit++;
    }
    else if (bam_counter == 24)
    {
        bam_bit++;
    }
    else if (bam_counter == 56)
    {
        bam_bit++;
    }

    // Here is where we increment the BAM counter
    bam_counter++;

    switch (bam_bit)
    {
        // The BAM bit will be a value from 0-3, and only shift out the arrays corresponding to that bit, 0-3
        // Here's how this works, each case is the bit in the Bit angle modulation from 0-4, 
        // Next, it depends on which level we're on, so the byte in the array to be written depends on which level, but since each level contains 64 LEDs,
        // we only shift out 8 bytes for each color
        case 0:
            for (int shift_out = level; shift_out < level + 8; shift_out++)
            {
                SPI.transfer(red0[shift_out]);
                SPI.transfer(green0[shift_out]);
                SPI.transfer(blue0[shift_out]);
            }
            break;

        case 1:
            for (int shift_out = level; shift_out < level + 8; shift_out++)
            {
                SPI.transfer(red1[shift_out]);
                SPI.transfer(green1[shift_out]);
                SPI.transfer(blue1[shift_out]);
            }
            break;

        case 2:
            for (int shift_out = level; shift_out < level + 8; shift_out++)
            {
                SPI.transfer(red2[shift_out]);
                SPI.transfer(green2[shift_out]);
                SPI.transfer(blue2[shift_out]);
            }
            break;

        case 3:
            for (int shift_out = level; shift_out < level + 8; shift_out++)
            {
                SPI.transfer(red3[shift_out]);
                SPI.transfer(green3[shift_out]);
                SPI.transfer(blue3[shift_out]);
            }

            //! *****************************************************************************************************
            // Here is where the bam_counter is reset back to 0, it's only 4 bit, but since each cycle takes 8 counts,
            // it goes 0 8 16 32, and when BAM_counter hits 64 we reset the BAM
            if (bam_counter == 120)
            {
                bam_counter = 0;
                bam_bit = 0;
            }
            break;
    }

    switch (cathode_level)
    {
        case 0:
            cathode = 0b11111110;
            break;

        case 1:
            cathode = 0b11111101;
            break;

        case 2:
            cathode = 0b11111011;
            break;

        case 3:
            cathode = 0b11110111;
            break;

        case 4:
            cathode = 0b11101111;
            break;

        case 5:
            cathode = 0b11011111;
            break;

        case 6:
            cathode = 0b10111111;
            break;

        case 7:
            cathode = 0b01111111;
            break;
    }

    SPI.transfer(cathode);                 // Sends out the cathode level byte

    digitalWrite(latch_pin, HIGH);         // Latch pin HIGH
    digitalWrite(latch_pin, LOW);          // Latch pin LOW
    digitalWrite(blank_pin, LOW);          // Blank pin LOW to turn on the LEDs with the new data

    cathode_level++;
    level = level + 8;                     // Increment the level variable by 8, which is used to shift out data, since the next level woudl be the next 8 bytes in the arrays

    if (cathode_level == 8)                // Go back to 0 if max is reached
    {
        cathode_level = 0;
    }
    if (level == 64)                       // If you hit 64 on level, this means you just sent out all 63 bytes, so go back
    {
        level = 0;
    }

    pinMode(blank_pin, OUTPUT);            // Moved down here so outputs are all off until the first call of this function

    SPI.endTransaction();                  // End serial transaction
}