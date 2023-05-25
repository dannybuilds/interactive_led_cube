#include "terminal.h"
#include <ncurses.h>

// Initialize the terminal
void terminal_init(void) {
    initscr(); // Initialize the library
    raw();     // Disable line buffering
    keypad(stdscr, TRUE); // Enable special keys
    noecho();  // Don't echo user input
}

// Display the main menu
void terminal_display_menu(void) {
    printw("1. Initialize LED cube\n");
    printw("2. Set LED color\n");
    printw("3. Update LED cube\n");
    printw("4. Exit\n");
    printw("Enter your choice: ");
    refresh(); // Update the screen
}

// Handle user input
void terminal_handle_input(void) {
    int choice = getch(); // Get user input

    switch (choice) {
        case '1':
            // Call the function to initialize the LED cube
            break;
        case '2':
            // Call the function to set an LED color
            break;
        case '3':
            // Call the function to update the LED cube
            break;
        case '4':
            // Exit the program
            endwin(); // End ncurses mode
            exit(0);
        default:
            printw("Invalid choice. Please try again.\n");
    }
    refresh(); // Update the screen
}