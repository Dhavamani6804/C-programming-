#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printArray(int arr[], int size, int mode);
void reverseArray(int arr[], int size);
void sortArray(int arr[], int size, int order);

int main() {
    int *arr = NULL;
    int size = 0;
    int choice, sortOrder;
    
    do {
        printf("\n-------ARRAY MENU-------\n\n");
        printf("1. Input elements for array\n");
        printf("2. Print array elements\n");
        printf("3. Reverse array elements\n");
        printf("4. Sort array elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Input elements
                printf("Enter the number of elements: ");
                scanf("%d", &size);
                
                // Free old array if exists
                if(arr != NULL) {
                    free(arr);
                }
                
                // Allocate memory for new array
                arr = (int*)malloc(size * sizeof(int));
                if(arr == NULL) {
                    printf("Memory allocation failed!\n");
                    size = 0;
                    break;
                }
                
                printf("Enter %d elements:\n", size);
                for(int i = 0; i < size; i++) {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                printf("Array updated successfully!\n");
                break;
                
            case 2: // Print array
                if(size == 0 || arr == NULL) {
                    printf("Array is empty! Please input elements first.\n");
                    break;
                }
                
                printf("\n--- Print Options ---\n\n");
                printf("1. All elements\n");
                printf("2. Only odd numbers\n");
                printf("3. Only even numbers\n");
                printf("Enter print option: ");
                int printOption;
                scanf("%d", &printOption);
                
                if(printOption >= 1 && printOption <= 3) {
                    printArray(arr, size, printOption);
                } else {
                    printf("Invalid print option!\n");
                }
                break;
                
            case 3: // Reverse array
                if(size == 0 || arr == NULL) {
                    printf("Array is empty! Please input elements first.\n");
                    break;
                }
                
                reverseArray(arr, size);
                printf("Array reversed successfully!\n");
                printf("Reversed array: ");
                printArray(arr, size, 1);
                break;
                
            case 4: // Sort array
                if(size == 0 || arr == NULL) {
                    printf("Array is empty! Please input elements first.\n");
                    break;
                }
                
                printf("\n--- Sort Options ---\n\n");
                printf("1. Ascending order\n");
                printf("2. Descending order\n");
                printf("Enter sort order: ");
                scanf("%d", &sortOrder);
                
                if(sortOrder == 1 || sortOrder == 2) {
                    sortArray(arr, size, sortOrder);
                    printf("Array sorted successfully!\n");
                    printf("Sorted array: ");
                    printArray(arr, size, 1);
                } else {
                    printf("Invalid sort order!\n");
                }
                break;
                
            case 5: 
                printf("Exiting program...\n");
                // Free allocated memory
                if(arr != NULL) {
                    free(arr);
                }
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}

// Function to print array based on mode
void printArray(int arr[], int size, int mode) {
    int printed = 0;
    
    switch(mode) {
        case 1: // All elements
            printf("Array elements: ");
            for(int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
            
        case 2: // Only odd numbers
            printf("Odd numbers: ");
            for(int i = 0; i < size; i++) {
                if(arr[i] % 2 != 0) {
                    printf("%d ", arr[i]);
                    printed = 1;
                }
            }
            if(!printed) printf("No odd numbers found");
            printf("\n");
            break;
            
        case 3: // Only even numbers
            printf("Even numbers: ");
            for(int i = 0; i < size; i++) {
                if(arr[i] % 2 == 0) {
                    printf("%d ", arr[i]);
                    printed = 1;
                }
            }
            if(!printed) printf("No even numbers found");
            printf("\n");
            break;
    }
}

// Function to reverse array
void reverseArray(int arr[], int size) {
    int temp;
    for(int i = 0; i < size/2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// Function to sort array
void sortArray(int arr[], int size, int order) {
    int temp;
    
    // Bubble sort implementation
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(order == 1) { // Ascending
                if(arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            } else { // Descending
                if(arr[j] < arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}