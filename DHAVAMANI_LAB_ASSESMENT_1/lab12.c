#include <stdio.h>

// Define macros for each bit
#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

// Macros to read bits
#define READ_BIT(var, bit) (((var) >> (bit)) & 1)
// Macros to set bits
#define SET_BIT(var, bit) ((var) |= (1 << (bit)))
// Macros to clear bits
#define CLEAR_BIT(var, bit) ((var) &= ~(1 << (bit)))

int main() {
    unsigned char Input = 0;
    int temp;
    
    // Get input from user
    printf("Enter a number between 0-255: ");
    scanf("%d", &temp);
    
    if (temp < 0 || temp > 255) {
        printf("Invalid input! Number must be between 0-255.\n");
        return 1;
    }
    
    Input = (unsigned char)temp;
    printf("\nOriginal Input: %u\n", Input);
    
    unsigned char original = Input;
    
    if (READ_BIT(Input, D0)) {
        // If D0 is high, set D6 (Ignition Status) high
        SET_BIT(Input, D6);
        printf("Ignition Switch: ON\n");
        
        // Check indicator switches
        int right_switch = READ_BIT(Input, D1);
        int left_switch = READ_BIT(Input, D2);
        
        if (right_switch && left_switch) {
            // Both indicator switches ON - parking mode
            CLEAR_BIT(Input, D5);  
            CLEAR_BIT(Input, D7);  
            printf("PARKING ON\n");
        } else {
            // handle right indicator
            if (right_switch) {
                SET_BIT(Input, D5);
                printf("RIGHT INDICATOR ON\n");
            } else {
                CLEAR_BIT(Input, D5);
            }
            
            // handle left indicator
            if (left_switch) {
                SET_BIT(Input, D7);
                printf("LEFT INDICATOR ON\n");
            } else {
                CLEAR_BIT(Input, D7);
            }
        }
    } else {
        // If D0 is low, clear D6 (Ignition Status)
        CLEAR_BIT(Input, D6);
        printf("Ignition Switch: OFF\n");
        
        // Clear indicator status
        CLEAR_BIT(Input, D5);
        CLEAR_BIT(Input, D7);
        
        int right_switch = READ_BIT(Input, D1);
        int left_switch = READ_BIT(Input, D2);
        
        if (right_switch) {
            printf("Right Indicator Switch is ON (but status is OFF)\n");
        }
        if (left_switch) {
            printf("Left Indicator Switch is ON (but status is OFF)\n");
        }
        if (right_switch && left_switch) {
            printf("Both switches ON (but PARKING is OFF)\n");
        }
    }
    
    // Print the modified value
    printf("\nModified Input: %u\n", Input);
    
    // Print binary representation
    printf("Binary: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", READ_BIT(Input, i));
    }
    printf(" (D7 D6 D5 D4 D3 D2 D1 D0)\n");
    
    return 0;
}