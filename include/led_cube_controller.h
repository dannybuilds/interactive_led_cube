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