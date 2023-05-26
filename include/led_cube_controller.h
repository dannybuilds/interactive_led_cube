// Authors :  Danny Restrepo
//         :  Bodgan Gula
//         :  Mark Gelman
//         :  Nitin Suryadevara
// Emails  :  restrepo@pdx.edu
//         :  gula@pdx.edu
//         :  gelman@pdx.edu
//         :  nitin2@pdx.edu
// Course  :  ECE103 Engineering Programming
// School  :  Portland State University
// Date    :  25th May 2023
// Project :  Interactive LED Cube



#ifndef LED_CUBE_CONTROLLER_H
#define LED_CUBE_CONTROLLER_H

#include <stdint.h>

// Define the size of the LED cube
#define LED_CUBE_SIZE 8

// Define the structure for an RGB color
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGBColor;

// Initialize the LED cube
void led_cube_init(void);

// Set the color of a specific LED
void led_cube_set_led(int x, int y, int z, RGBColor color);

// Update the entire LED cube
void led_cube_update(void);

#endif // LED_CUBE_CONTROLLER_H