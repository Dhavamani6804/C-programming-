#include <stdio.h>

// Macros for bit operations
#define READBIT(num, bit) ((num >> bit) & 1)
#define SETBIT(num, bit) (num |= (1 << bit))
#define RESETBIT(num, bit) (num &= ~(1 << bit))

int main() {
    unsigned char InputValue, OutputValue = 0;
    
    // Get value from user
    printf("Enter a number: ");
    scanf("%hhu", &InputValue);
    
    printf("\nReading last 4 bits of InputValue:\n");
    
    // Read last 4 bits and set/reset MSB 4 bits of OutputValue
    for(int i = 0; i < 4; i++) {
        // Read current bit from InputValue
        if(READBIT(InputValue, i)) {
            // If bit is 1, set corresponding MSB bit in OutputValue
            SETBIT(OutputValue, 4 + i);
        } else {
            // If bit is 0, reset corresponding MSB bit in OutputValue
            RESETBIT(OutputValue, 4 + i);
        }
    }
    
    // Print the result
    printf("\nOutputValue: %u\n", OutputValue);
    
    return 0;
}