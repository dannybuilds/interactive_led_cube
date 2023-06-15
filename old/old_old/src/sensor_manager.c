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

#include "sensor_manager.h"
#include "driver/uart.h"

// Define the UART port for the sensor data
#define SENSOR_UART_PORT UART_NUM_1



// This would be the actual hardware-specific code to initialize your sensor manager
void sensor_manager_init(void)
{
    // Initialize the UART port for the sensor data
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(SENSOR_UART_PORT, &uart_config);
    uart_driver_install(SENSOR_UART_PORT, 1024, 0, 0, NULL, 0);
}


// This would be the actual hardware-specific code to get the sensor data for a specific point
Point3D sensor_manager_get_data(int x, int y, int z)
{
    // Get the sensor data for the point at position (x, y, z)
    // This is a placeholder and would need to be replaced with actual code to read data from your sensor system
    Point3D point = { x, y, z };
    return point;
}