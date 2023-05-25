#ifndef OBJECT_DETECTION_H
#define OBJECT_DETECTION_H

#include <stdint.h>
#include "sensor_manager.h"

// Define the size of the object data
#define OBJECT_DATA_SIZE 8

// Define the structure for an object in 3D space
typedef struct {
    Point3D points[OBJECT_DATA_SIZE][OBJECT_DATA_SIZE][OBJECT_DATA_SIZE];
} Object3D;

// Initialize the object detection
void object_detection_init(void);

// Get the 3D representation of an object
Object3D object_detection_get_object(void);

#endif // OBJECT_DETECTION_H