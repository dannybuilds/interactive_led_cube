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

#include "led_cube_controller.h"
#include "driver/gpio.h"

// Define the GPIO pins for the LED cube
#define LED_CUBE_GPIO_RED   GPIO_NUM_25
#define LED_CUBE_GPIO_GREEN GPIO_NUM_26
#define LED_CUBE_GPIO_BLUE  GPIO_NUM_27



// This would be the actual hardware-specific code to initialize your LED cube
void led_cube_init(void)
{
    // Initialize the GPIO pins for the LED cube
    gpio_pad_select_gpio(LED_CUBE_GPIO_RED);
    gpio_pad_select_gpio(LED_CUBE_GPIO_GREEN);
    gpio_pad_select_gpio(LED_CUBE_GPIO_BLUE);

    // Set the GPIO pins as outputs
    gpio_set_direction(LED_CUBE_GPIO_RED, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_CUBE_GPIO_GREEN, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_CUBE_GPIO_BLUE, GPIO_MODE_OUTPUT);
}


// This would be the actual hardware-specific code to set the color of a specific LED
void led_cube_set_led(int x, int y, int z, RGBColor color)
{
    // Set the color of the LED at position (x, y, z) to the specified color
    // This is a placeholder and would need to be replaced with actual code to control your specific LED cube
    gpio_set_level(LED_CUBE_GPIO_RED, color.r);
    gpio_set_level(LED_CUBE_GPIO_GREEN, color.g);
    gpio_set_level(LED_CUBE_GPIO_BLUE, color.b);
}


// This would be the actual hardware-specific code to update the entire LED cube
void led_cube_update(void)
{
    // Update the entire LED cube
    // This is a placeholder and would need to be replaced with actual code to control your specific LED cube
}