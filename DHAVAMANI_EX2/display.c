#include "main.h"

// External declaration of global variables
#if STAGE == 1
    extern int side;  // Declare external variable for square side
    
#elif STAGE == 2
    extern float radius;  // Declare external variable for circle radius
    
#endif

void display_area(void) {
    printf("Calculating area for %s:\n", SHAPE_NAME);
    
    #if STAGE == 1
        printf("Side length: %d units\n", side);
        printf("Area = %d square units\n", AREA(side));
        
    #elif STAGE == 2
        printf("Radius: %.2f units\n", radius);
        printf("Area = %.2f square units\n", AREA(radius));
        
    #endif
}