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
// Title   :  Animation Function Prototypes, Header File

#ifndef ANIMATIONS_H
#define ANIMATIONS_H



void set_led(int level, int row, int column, byte red, byte green, byte blue);

void IRAM_ATTR onTimer();

void wipe_out();

void rain();

void folder();

void bouncy();

void sine_wave();

void color_wheel();

void color_wheel_v2();

void harlem_shake();

void clean();



#endif /* ANIMATIONS_H */