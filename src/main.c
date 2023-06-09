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

/*
    Program Description:

    //* FILL IN LATER //
*/

/******************************** Header files ********************************/

#include "main.h"
#include "led_cube_controller.h"
#include "sensor_manager.h"
#include "object_detection.h"
#include "terminal.h"
#include "diagnostic.h"
#include "curses.h"
#include <stdio.h>



// Start the main program loop
void main_loop(void)
{
    // Initialize all modules
    led_cube_init();
    sensor_manager_init();
    object_detection_init();
    terminal_init();
    diagnostic_run_tests();

    // Display the main menu
    terminal_display_menu();

    // Enter the main program loop
    while (1)
    {
        // Handle user input
        terminal_handle_input();

        // Update the LED cube
        led_cube_update();

        // Display the current system status
        diagnostic_display_status();
    }
}


int main(void)
{
    // Start the main program loop
    main_loop();

    return 0;
}