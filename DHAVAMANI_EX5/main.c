#include <stdio.h>

// Function prototypes
void displayArray(int arr[], int size);
int countEvenNumbers(int arr[], int size);
void sortAscending(int arr[], int size);
void sortDescending(int arr[], int size);
void removeDuplicates(int arr[], int size);

int main() {
    int arr[10];
    int ascending[10], descending[10];
    int i;
    
    // Input 10 array elements
    printf("Enter 10 integer elements:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n=========ARRAY OPERATIONS=========\n");
    
    // Display original array
    printf("\nOriginal Array: ");
    displayArray(arr, 10);
    
    // 1. Count even numbers
    printf("\n1. Even Numbers Count: %d\n", countEvenNumbers(arr, 10));
    
    // 2. Sort in ascending order
    // Copy array for sorting
    for(i = 0; i < 10; i++) {
        ascending[i] = arr[i];
    }
    sortAscending(ascending, 10);
    printf("2. Ascending Order: ");
    displayArray(ascending, 10);
    
    // 3. Sort in descending order
    // Copy array for sorting
    for(i = 0; i < 10; i++) {
        descending[i] = arr[i];
    }
    sortDescending(descending, 10);
    printf("3. Descending Order: ");
    displayArray(descending, 10);
    
    // 4. Remove duplicate numbers
    printf("4. Without Duplicates: ");
    removeDuplicates(arr, 10);
    
    return 0;
}

// Function to display array
void displayArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to count even numbers
int countEvenNumbers(int arr[], int size) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Function to sort array in ascending order
void sortAscending(int arr[], int size) {
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to sort array in descending order
void sortDescending(int arr[], int size) {
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to remove and print without duplicates
void removeDuplicates(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int isDuplicate = 0;
        
        // Check if current element appears before
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        
        // Print if not duplicate
        if(!isDuplicate) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}