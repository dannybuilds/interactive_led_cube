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



#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <stdint.h>

// Define the size of the sensor data
#define SENSOR_DATA_SIZE 8

// Define the structure for a point in 3D space
typedef struct {
    int x;
    int y;
    int z;
} Point3D;

// Initialize the sensor manager
void sensor_manager_init(void);

// Get the sensor data for a specific point
Point3D sensor_manager_get_data(int x, int y, int z);

#endif // SENSOR_MANAGER_H