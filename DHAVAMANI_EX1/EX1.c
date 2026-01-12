#include <stdio.h>

int main() {
    // Declare variables
    int intVar;
    float floatVar;
    
    // Input values
    printf("Enter an integer value: ");
    scanf("%d", &intVar);
    
    printf("Enter a float value: ");
    scanf("%f", &floatVar);
    
    // Display values
    printf("\n--- Variable Details ---\n");
    printf("Integer value: %d\n", intVar);
    printf("Float value: %.2f\n", floatVar);
    
    // Display sizes
    printf("Size of integer variable: %zu bytes\n", sizeof(intVar));
    printf("Size of float variable: %zu bytes\n", sizeof(floatVar));
    
    return 0;
}