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
// Title   :  Terminal Menu Module, Source File

/*
    Program Description:
        Creates PDCurses Window object and customizes it for an
        effortless and pleasing menu select user experience.
*/



/***************************** Includes & Macros ******************************/
#include <curses.h>
#include <string.h>
#include "menu.h"



int menu_select()
{
    // Initialize the library
    initscr();

    // Start color functionality
    start_color();

    // Define colors
    init_pair(1, COLOR_BLUE, COLOR_YELLOW);  // Blue for border
    init_pair(2, COLOR_BLUE, COLOR_YELLOW);  // Blue text on yellow background
    init_pair(3, COLOR_YELLOW, COLOR_BLUE);  // Yellow text on blue background for highlighted item
    init_pair(4, COLOR_RED, COLOR_YELLOW);   // Red for title
    init_pair(5, COLOR_BLACK, COLOR_GREEN);  // Black for border on second screen
    init_pair(6, COLOR_BLACK, COLOR_GREEN);  // Black text on green background for second screen
    init_pair(7, COLOR_RED, COLOR_GREEN);    // Red text on green background for second screen

    // Create a window for the menu
    WINDOW* menuwin = newwin(40, 120, (LINES - 40) / 2, (COLS - 120) / 2);
    keypad(menuwin, TRUE);                   // Enable keyboard mapping
    wbkgd(menuwin, COLOR_PAIR(2));           // Set the background color to yellow
    box(menuwin, 0, 0);
    refresh();

    // Set the color of the border of the menu
    wattron(menuwin, COLOR_PAIR(1));
    box(menuwin, 0, 0);
    wattroff(menuwin, COLOR_PAIR(1));

    // The options for the menu
    const char* options[] =
    {
        "Run program",
        "Sine Wave animation",
        "Rain animation",
        "Folding Plane animation",
        "Wipe Out animation",
        "Bouncy Particle animation",
        "Color Wheel animation",
        "Harlem Shake animation",
        "Clear LED Display",
        "Diagnostic Mode"
    };

    // The number of options
    int num_options = sizeof(options) / sizeof(char*);

    // The highlighted option
    int highlight = 0;

    int choice = -1;
    int c;

    while (1)
    {
        // Print the title
        wattron(menuwin, COLOR_PAIR(4));
        mvwprintw(menuwin, 11, (120 - strlen("LED Cube Main Menu: Choose an Option")) / 2, "LED Cube Main Menu: Choose an Option");
        wattroff(menuwin, COLOR_PAIR(4));

        for (int i = 0; i < num_options; ++i)
        {
            if (i == highlight)
                wattron(menuwin, COLOR_PAIR(3));
            else
                wattron(menuwin, COLOR_PAIR(2));
            mvwprintw(menuwin, i + 14, (120 - strlen(options[i])) / 2, options[i]);
            if (i == highlight)
                wattroff(menuwin, COLOR_PAIR(3));
            else
                wattroff(menuwin, COLOR_PAIR(2));
        }

        c = wgetch(menuwin);

        switch (c)
        {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == num_options)
                    highlight = num_options - 1;
                break;
            case 10:
                choice = highlight;
                break;
            default:
                break;
        }

        // If Enter is pressed, call the appropriate function
        if (choice != -1 && c == 10)
        {
            // Only proceed if Enter is pressed
            // Clear the menu window
            wclear(menuwin);
            // Set the background color to green
            wbkgd(menuwin, COLOR_PAIR(6));
            box(menuwin, 0, 0);
            wattron(menuwin, COLOR_PAIR(5));
            box(menuwin, 0, 0);
            wattroff(menuwin, COLOR_PAIR(5));

            // Print the selected option
            wattron(menuwin, COLOR_PAIR(6));
            mvwprintw(menuwin, 16, (120 - strlen("Now running...")) / 2, "Now running...");
            mvwprintw(menuwin, 17, (120 - strlen(options[choice])) / 2, "%s", options[choice]);
            wattroff(menuwin, COLOR_PAIR(6));

            // Print the return instruction
            wattron(menuwin, COLOR_PAIR(7));
            mvwprintw(menuwin, 20, (120 - strlen("(Press any button to return.)")) / 2, "(Press any button to return.)");
            wattroff(menuwin, COLOR_PAIR(7));

            wrefresh(menuwin);

            // Wait for any key press
            wgetch(menuwin);

            // Reset the window
            wclear(menuwin);
            // Set the background color back to yellow
            wbkgd(menuwin, COLOR_PAIR(2));
            wattron(menuwin, COLOR_PAIR(1));
            box(menuwin, 0, 0);
            wattroff(menuwin, COLOR_PAIR(1));
            break; // Exit the loop
        }
    }

    // Clean up and close
    clrtoeol();
    refresh();
    endwin();

    // Return the selected menu item
    return choice;
}