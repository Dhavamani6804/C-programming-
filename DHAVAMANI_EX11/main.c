#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNewList(int data);
void addAtFront(struct Node** head, int data);
void addAtBack(struct Node** head, int data);
void printList(struct Node* head);
void freeList(struct Node* head);

// Function to create a new linked list with first node
struct Node* createNewList(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    printf("Created new list with initial data: %d\n", data);
    return newNode;
}

// Function to add node at the front of the list
void addAtFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Added %d at the front\n", data);
}

// Function to add node at the back of the list
void addAtBack(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    // If list is empty, new node becomes head
    if (*head == NULL) {
        *head = newNode;
        printf("Added %d at the back (list was empty)\n", data);
        return;
    }
    
    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Added %d at the back\n", data);
}

// Function to print all data in the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to free all allocated memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function 
int main() {
    struct Node* head = NULL;
    int choice, data;
    
    
    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Create new list\n");
        printf("2. Add node at front\n");
        printf("3. Add node at back\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (head != NULL) {
                    freeList(head);
                }
                printf("Enter initial data: ");
                scanf("%d", &data);
                head = createNewList(data);
                break;
                
            case 2:
                if (head == NULL) {
                    printf("List is empty! Create a list first.\n");
                    break;
                }
                printf("Enter data to add at front: ");
                scanf("%d", &data);
                addAtFront(&head, data);
                break;
                
            case 3:
                if (head == NULL) {
                    printf("List is empty! Create a list first.\n");
                    break;
                }
                printf("Enter data to add at back: ");
                scanf("%d", &data);
                addAtBack(&head, data);
                break;
                
            case 4:
                printList(head);
                break;
                
            case 5:
                printf("Exiting...\n");
                freeList(head);
                return 0;
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}