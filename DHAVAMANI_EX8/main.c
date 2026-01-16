#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 5
#define MAX_NAME 100

// Structure to store book details 
struct Book {
    char name[MAX_NAME];
    float price;
    int id;
};

// Function to upload details of books 
void uploadBooks(struct Book books[], int size) {

    printf("\n=== UPLOAD BOOK DETAILS ===\n");
    
    for (int i = 0; i < size; i++) {
        printf("\n--- Enter details for Book %d ---\n", i + 1);
        
        // Get Book ID
        printf("Enter Book ID: ");
        scanf("%d", &books[i].id);
        getchar(); 
        
        // Get Book Name
        printf("Enter Book Name: ");
        fgets(books[i].name, MAX_NAME, stdin);
        
        // Remove trailing newline from fgets
        books[i].name[strcspn(books[i].name, "\n")] = '\0';
        
        // Get Book Price
        printf("Enter Book Price: ");
        scanf("%f", &books[i].price);
    }
    
    printf("\n%d books uploaded successfully!\n", size);
}

// Function to print book information based on ID
void printBookByID(struct Book books[], int size, int searchID) {

    int found = 0; // Flag to check if book is found
    
    for (int i = 0; i < size; i++) {
        if (books[i].id == searchID) {
            printf("\n=== BOOK FOUND ===\n");
            printf("Book ID: %d\n", books[i].id);
            printf("Book Name: %s\n", books[i].name);
            printf("Book Price: $%.2f\n", books[i].price);
            found = 1;
            break; 
        }
    }
    
    if (!found) {
        printf("\nBook with ID %d not found in the library!\n", searchID);
    }
}

// Function to print all books information 
void displayAllBooks(struct Book books[], int size) {

    if (size == 0) {
        printf("\nNo books in the library!\n");
        return;
    }
    
    printf("\nALL BOOKS IN LIBRARY\n");
    printf("\n|  ID  |                     NAME                      |  PRICE   |\n\n");
    
    for (int i = 0; i < size; i++) {
        printf("| %4d | %-45s | $%7.2f |\n", 
               books[i].id, books[i].name, books[i].price);
    }
    
    printf("\n");
}

int main() {

    struct Book library[MAX_BOOKS]; 
    int choice;
    int searchID;
    
    printf("\n-----LIBRARY MANAGEMENT SYSTEM-----\n");
    
    uploadBooks(library, MAX_BOOKS);
    
    displayAllBooks(library, MAX_BOOKS);
    
    do {
        printf("\n----SEARCH MENU----\n");
        printf("1. Search book by ID\n");
        printf("2. Display all books\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter Book ID to search: ");
                scanf("%d", &searchID);
                printBookByID(library, MAX_BOOKS, searchID);
                break;
                
            case 2:
                displayAllBooks(library, MAX_BOOKS);
                break;
                
            case 3:
                printf("\nThank you for using Library Management System!\n");
                printf("Exiting...\n");
                break;
                
            default:
                printf("\nInvalid choice! Please enter 1, 2, or 3.\n");
        }
        
    } while (choice != 3);
    
    return 0;
}