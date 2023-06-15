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
#include <math.h>                // Math C Library needed for sine() function
#include <Arduino.h>             // For the byte data type
// #include "animations.h"          // Function prototypes for animations module
// #include "menu.h"                // Function prototypes for menu module

#define ROWS 8                   // Number of horizontal rows per layer, anodes
#define COLS 8                   // Number of horizontal columns per layer, anodes
#define LAYERS 8                 // Number of vertical layers in cube display, cathodes
#define OUTPUTS_PER_SR 8         // Number of parallel outputs per shift register
#define NUM_OF_SR 25             // Total number of shift registers

const int latch_pin = 21;        // RCLK (storage clock, latch), positive edge triggered
const int data_pin = 18;         // SER, used for serial input on the shift register daisy chains
const int clock_pin = 5;         // SRCLK, used by SPI, must be GPIO5
const int clear_pin = 26;        // SRCLR, used for prepping registers for data input, active low

byte red_data[LAYERS][ROWS][COLS] = { 0 };      // 4096 bits, 8 per individual LED channel
byte green_data[LAYERS][ROWS][COLS] = { 0 };    // 4096 bits, 8 per individual LED channel
byte blue_data[LAYERS][ROWS][COLS] = { 0 };     // 4096 bits, 8 per individual LED channel
byte display_serial_out[NUM_OF_SR] = { 0 };     // 200 bits, 1 per register output


//! ****************************************************************************
// Assuming global storage arrays are defined as:
// byte red_data[8][8][8], green_data[8][8][8], blue_data[8][8][8];
const float PI = 3.14159265358979323846;
//! ****************************************************************************


/********************************* Prototypes *********************************/
void reset_storage(void);
void pulse_width_mod(void);
void diagnose(const byte data, const char name[]);
void set_led_data(const int level, const int row, const int col,
                  const byte red, const byte green, const byte blue);

//! ****************************************************************************
void sineWaveAnimation(float time);
byte floatToColor(float value);
void rainbow(float value, byte &r, byte &g, byte &b);
//! ****************************************************************************


/******************************** Sketch Setup ********************************/
void setup()
{
    // 
    pinMode(latch_pin, OUTPUT);
    pinMode(data_pin, OUTPUT);
    pinMode(clock_pin, OUTPUT);
    pinMode(clear_pin, OUTPUT);

    // 
    digitalWrite(latch_pin, LOW);

    // 
    digitalWrite(clear_pin, LOW);
    digitalWrite(clear_pin, HIGH);

    // Highest setting
    Serial.begin(512000);
}



/******************************** Sketch Loop *********************************/
void loop()
{
    // Time in seconds, increments in 1/60 second steps
    static float time = 0.0;

    // Update sine wave animation with current time
    sineWaveAnimation(time);

    // Increment time
    time += 1.0 / 60.0;

    // Delay to achieve approximately 60 frames per second
    delay(1000 / 60);
}



/*********************** LED Color Data Storage Routine ***********************/
void set_led_data(const int cathode_level, const int anode_row, const int anode_col,
                  const byte red, const byte green, const byte blue)
{
    red_data[cathode_level][anode_row][anode_col] = red;
    green_data[cathode_level][anode_row][anode_col] = green;
    blue_data[cathode_level][anode_row][anode_col] = blue;
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
void pulse_width_mod()
{
    // Tracks which bit the program is currently "viewing"
    // (per byte)
    int bit_index;

    // Tracks which register the program is currently "viewing"
    // (for the whole daisy chain)
    int register_index = 1;

    // Traverses through each vertical layer of cube
    // (layers parallel with ground, i.e. horizontal cuts)
    for (int vertical = 0; vertical < LAYERS; vertical++)
    {
        // Resets layer selection for a 1/8 duty cycle 
        // per vertical layer (at best)
        display_serial_out[0] = 0;

        // Serial out for vertical layer selection
        // Cathode control
        bitSet(display_serial_out[0], vertical);

        // Serial out for BLUE channel daisy chain of shift registers
        // Anode control
        for (int pwm_b = 0; pwm_b < 256; pwm_b++)
        {
            for (int rows_b = 0; rows_b < ROWS; rows_b++)
            {
                // Resets bit counter at the start of every shift register
                bit_index = 0;

                for (int cols_b = 0; cols_b < COLS; cols_b++)
                {
                    // If BLUE intensity value for the pixel is below than the threshold
                    if (blue_data[vertical][rows_b][cols_b] < pwm_b)
                    {
                        // Error checking
                        assert(register_index >= 0 && register_index <= 25);
                        assert(bit_index >= 0 && bit_index <= 7);

                        // The the BLUE channel gets turned on
                        bitSet(display_serial_out[register_index], bit_index);
                    }
                    // Moves onto the next bit in the byte 
                    bit_index++;
                }
                // Moves onto the next register in daisy chain 
                register_index++;
            }
        }

        // Serial out for GREEN channel daisy chain of shift registers
        // Anode control
        for (int pwm_g = 0; pwm_g < 256; pwm_g++)
        {
            for (int row_g = 0; row_g < ROWS; row_g++)
            {
                // Resets bit counter at the start of every shift register
                bit_index = 0;

                for (int cols_g = 0; cols_g < COLS; cols_g++)
                {
                    // If GREEN intensity value for the pixel is below than the threshold
                    if (green_data[vertical][row_g][cols_g] < pwm_g)
                    {
                        // Error checking
                        assert(register_index >= 0 && register_index <= 25);
                        assert(bit_index >= 0 && bit_index <= 7);

                        // The the GREEN channel gets turned on
                        bitSet(display_serial_out[register_index], bit_index);
                    }
                    // Moves onto the next bit in the byte 
                    bit_index++;
                }
                // Moves onto the next register in daisy chain 
                register_index++;
            }
        }

        // Serial out for RED channel daisy chain of shift registers
        // Anode control
        for (int pwm_r = 0; pwm_r < 256; pwm_r++)
        {
            for (int rows_r = 0; rows_r < ROWS; rows_r++)
            {
                // Resets bit counter at the start of every shift register
                bit_index = 0;

                for (int cols_r = 0; cols_r < COLS; cols_r++)
                {
                    // If RED intensity value for the pixel is below than the threshold
                    if (red_data[vertical][rows_r][cols_r] < pwm_r)
                    {
                        // Error checking
                        assert(register_index >= 0 && register_index <= 25);
                        assert(bit_index >= 0 && bit_index <= 7);

                        // The the RED channel gets turned on
                        bitSet(display_serial_out[register_index], bit_index);
                    }
                    // Moves onto the next bit in the byte
                    bit_index++;
                }
                // Moves onto the next register in daisy chain
                register_index++;
            }
        }

        // Ensures data doesn't get sent to outputs of shift registers
        digitalWrite(latch_pin, LOW);

        // Shifts all of the store color data for this layer (in reverse)
        for (int n = NUM_OF_SR - 1; n >= 0; n--)
        {
            shiftOut(data_pin, clock_pin, LSBFIRST, display_serial_out[n]);
        }

        // Outputs (i.e. stores) shifted data at the desired timing
        digitalWrite(latch_pin, HIGH);
        // Prevents accidental data outputs, bug prevention
        digitalWrite(latch_pin, LOW);
    }

    delay(5);           // 
    reset_storage();    // 
}



void reset_storage()
{
    int i, j, k;

    for (i = 0; i < LAYERS; i++)
    {
        for (j = 0; j < ROWS; j++)
        {
            for (k = 0; k < COLS; k++)
            {
                set_led_data(i, j, k, 0, 0, 0);
            }
        }
    }
}




//! ****************************************************************************
// Convert a value in the range [0, 1] to [0, 255] for color intensity
byte floatToColor(float value)
{
    return (byte) (value * 255);
}
//! ****************************************************************************


//! ****************************************************************************
// Convert a value in the range [0, 1] to a rainbow color (R, G, B)
void rainbow(float value, byte &r, byte &g, byte &b)
{
    float red = sin(value * 2 * PI);
    float green = sin(value * 2 * PI + (2 * PI / 3));
    float blue = sin(value * 2 * PI + (4 * PI / 3));

    r = floatToColor((red + 1) / 2);
    g = floatToColor((green + 1) / 2);
    b = floatToColor((blue + 1) / 2);
}
//! ****************************************************************************


//! ****************************************************************************
// The animation function to display sine wave
void sineWaveAnimation(float time)
{
    const int center = 4;
    const float frequency = 0.2; // frequency of the wave
    const float amplitude = 3.0; // amplitude of the wave

    for (int z = 0; z < 8; z++)
    {
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                // Calculate distance from center
                float distance = sqrt(pow(x - center, 2) + pow(y - center, 2) + pow(z - center, 2));

                // Calculate sine wave value based on distance and time
                float sineValue = sin(distance * frequency + time) * amplitude;

                // Map the sine value to a color
                byte r, g, b;
                rainbow((sineValue + 1) / 2, r, g, b);

                // Set the LED color data
                set_led_data(z, y, x, r, g, b);
            }
        }
    }

    // Send the color data to the LEDs
    pulse_width_mod();
}
//! ****************************************************************************