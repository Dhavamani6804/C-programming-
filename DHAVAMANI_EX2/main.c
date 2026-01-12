#include "main.h"

// Conditional compilation for global variable declaration
#if STAGE == 1
    // Global variable for square side
    int side = 5;  
    
#elif STAGE == 2
    // Global variable for circle radius  
    float radius = 5;  
    
#endif

int main() {
    printf("\n\nShape Area Calculator\n\n");
    printf("Current STAGE: %d (%s)\n\n", STAGE, SHAPE_NAME);
    
    // Display the area based on current STAGE
    display_area();
    
    return 0;
}