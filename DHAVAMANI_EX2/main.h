#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

#define STAGE 2  // Define STAGE value 1 for Square, 2 for Circle

// Conditional compilation based on STAGE value
#if STAGE == 1
    // Area of Square: side * side
    #define AREA(s) ((s) * (s))
    #define SHAPE_NAME "Square"
    
#elif STAGE == 2
    // Area of Circle: π * radius * radius
    #define PI 3.14159
    #define AREA(r) (PI * (r) * (r))
    #define SHAPE_NAME "Circle"
    
#else
    #error "STAGE must be defined as 1 or 2"
#endif

// Function prototype
void display_area(void);

#endif 