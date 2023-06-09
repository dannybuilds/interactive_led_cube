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

// #include "terminal.h"
#include <curses.h>

// Define the number of menu options
#define NUM_MENU_OPTIONS 5



// Define the menu options
char* menu_options[] = {
    "Option 1",
    "Option 2",
    "Option 3",
    "Option 4",
    "Exit"
};


// Function to draw the menu
void draw_menu(int highlight)
{
    int x, y, i;

    x = 2; // Starting x coordinate
    y = 4; // Starting y coordinate

    // Draw a box for the menu
    attron(A_REVERSE);
    mvprintw(2, 2, "  Welcome to the Fancy Terminal Menu!  ");
    attroff(A_REVERSE);
    box(stdscr, 0, 0);

    for (i = 0; i < NUM_MENU_OPTIONS; i++)
    {
// Highlight the current selected menu option
        if (highlight == i + 1)
        {
            attron(A_BOLD | COLOR_PAIR(1)); // Change the color of the highlight
            mvprintw(y, x, "%s", menu_options[i]);
            attroff(A_BOLD | COLOR_PAIR(1));
        }
        else
        {
            mvprintw(y, x, "%s", menu_options[i]);
        }
        ++y;
    }
}


int main()
{
    int highlight = 1;
    int choice = 0;
    int c;

    // Initialize curses
    initscr();
    clear();
    noecho();
    cbreak();	// Line buffering disabled. Pass on everything

    // Initialize color
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE); // Initialize a color pair for the highlight

    // Draw the menu
    draw_menu(highlight);
    while (1)
    {
        c = getch();
        switch (c)
        {
            case KEY_UP:
                if (highlight == 1)
                    highlight = NUM_MENU_OPTIONS;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == NUM_MENU_OPTIONS)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10: // Enter key
                choice = highlight;
                break;
            default:
                refresh();
                break;
        }
        draw_menu(highlight);
        if (choice != 0)	// User made a choice come out of the infinite loop
            break;
    }
    clrtoeol();
    refresh();
    endwin();
    return 0;
}