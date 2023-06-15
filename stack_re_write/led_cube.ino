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
// #include "menu.h"                // Function prototypes for menu module

const int latch_pin = 21;        // GPIO21 will drive RCLK (latch) on shift registers
const int blank_pin = 26;        // Same, can use any pin you want for this, just make sure you pull up via a 1k to 5V
const int data_pin = 18;         // Used by SPI, must be GPIO18, used for serially driving the shift register daisy chains
const int clock_pin = 5;         // Used by SPI, must be GPIO5

int value = 0;
byte switch_var = 0;
byte display_data = 0;



/******************************** Sketch Setup ********************************/
void setup()
{
    pinMode(latch_pin, OUTPUT);
    pinMode(data_pin, OUTPUT);
    pinMode(clock_pin, OUTPUT);

    Serial.begin(9600);
}



/******************************** Sketch Loop *********************************/
void loop()
{
    update_registers();


}



/***************************** LED Update Routine *****************************/
void set_led(int cathode_level,
             int anode_row,
             int anode_column,
             byte red,
             byte green,
             byte blue)
{

}



/******************* Diagnostic Module for Debugging/Testing ******************/
void diagnose(const byte chosen_data, const char target_name[])
{
    char message[100];
    sprintf(message, "Binary data in the %s byte:  ", target_name);

    Serial.print(message);
    Serial.println(chosen_data, BIN);
}



/************** Latches Serial Data In to Registers' Parallel Out *************/
void update_registers()
{
    digitalWrite(latch_pin, LOW);
    shiftOUt(data_pin, clock_pin, LSBFIRST, display_data);
    digitalWrite(latch_pin, HIGH);
}