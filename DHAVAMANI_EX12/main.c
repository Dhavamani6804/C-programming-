#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// COMMON NODE STRUCTURE FOR STACK AND QUEUE
struct Node {
    int data;
    struct Node* next;
};

// STACK STRUCTURE
struct Stack {
    struct Node* top;
    int size;
    int capacity;
};

// Stack function prototypes
struct Stack* createStack();
bool isStackEmpty(struct Stack* s);
void push(struct Stack* s, int data);
int pop(struct Stack* s);
void displayStack(struct Stack* s);
void freeStack(struct Stack* s);

// QUEUE STRUCTURE 
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Queue function prototypes
struct Queue* createQueue();
bool isQueueEmpty(struct Queue* q);
void enqueue(struct Queue* q, int data);
int dequeue(struct Queue* q);
void displayQueue(struct Queue* q);
void freeQueue(struct Queue* q);

// STACK FUNCTIONS IMPLEMENTATION

struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = NULL;
    s->size = 0;
    s->capacity = 0;  // Unlimited capacity
    return s;
}

bool isStackEmpty(struct Stack* s) {
    return s->top == NULL;
}

void push(struct Stack* s, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    printf("Pushed %d to stack\n", data);
}

int pop(struct Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    
    struct Node* temp = s->top;
    int poppedData = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return poppedData;
}

void displayStack(struct Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack: [Empty]\n");
        return;
    }
    
    printf("Stack (Top to Bottom): ");
    struct Node* current = s->top;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void freeStack(struct Stack* s) {
    while (!isStackEmpty(s)) {
        pop(s);
    }
    free(s);
}

// QUEUE FUNCTIONS IMPLEMENTATION

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    printf("Enqueued %d to queue\n", data);
}

int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    struct Node* temp = q->front;
    int dequeuedData = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    q->size--;
    return dequeuedData;
}

void displayQueue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue: [Empty]\n");
        return;
    }
    
    printf("Queue (Front to Rear): ");
    struct Node* current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void freeQueue(struct Queue* q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// MAIN FUNCTION 
int main() {
    struct Stack* myStack = NULL;
    struct Queue* myQueue = NULL;
    int mainChoice, operationChoice, data;
    
    while (1) {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);
        
        switch (mainChoice) {
            case 1: // Stack Operations
                if (myStack == NULL) {
                    myStack = createStack();
                    printf("New stack created\n");
                }
                
                while (1) {
                    printf("\n--- Stack Operations ---\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Check if Empty\n");
                    printf("4. Display Stack\n");
                    printf("5. Back to Main Menu\n");
                    printf("Enter operation choice: ");
                    scanf("%d", &operationChoice);
                    
                    switch (operationChoice) {
                        case 1: // Push
                            printf("Enter value to push: ");
                            scanf("%d", &data);
                            push(myStack, data);
                            break;
                            
                        case 2: // Pop
                            data = pop(myStack);
                            if (data != -1) {
                                printf("Popped value: %d\n", data);
                            }
                            break;
                            
                        case 3: // Check if Empty
                            if (isStackEmpty(myStack)) {
                                printf("Stack is empty\n");
                            } else {
                                printf("Stack is not empty\n");
                            }
                            break;
                            
                        case 4: // Display Stack
                            displayStack(myStack);
                            break;
                            
                        case 5: // Back to Main Menu
                            goto stack_exit;
                            
                        default:
                            printf("Invalid operation choice!\n");
                    }
                }
                stack_exit:
                break;
                
            case 2: // Queue Operations
                if (myQueue == NULL) {
                    myQueue = createQueue();
                    printf("New queue created\n");
                }
                
                while (1) {
                    printf("\n--- Queue Operations ---\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Check if Empty\n");
                    printf("4. Display Queue\n");
                    printf("5. Back to Main Menu\n");
                    printf("Enter operation choice: ");
                    scanf("%d", &operationChoice);
                    
                    switch (operationChoice) {
                        case 1: // Enqueue
                            printf("Enter value to enqueue: ");
                            scanf("%d", &data);
                            enqueue(myQueue, data);
                            break;
                            
                        case 2: // Dequeue
                            data = dequeue(myQueue);
                            if (data != -1) {
                                printf("Dequeued value: %d\n", data);
                            }
                            break;
                            
                        case 3: // Check if Empty
                            if (isQueueEmpty(myQueue)) {
                                printf("Queue is empty\n");
                            } else {
                                printf("Queue is not empty\n");
                            }
                            break;
                            
                        case 4: // Display Queue
                            displayQueue(myQueue);
                            break;
                            
                        case 5: // Back to Main Menu
                            goto queue_exit;
                            
                        default:
                            printf("Invalid operation choice!\n");
                    }
                }
                queue_exit:
                break;
                
            case 3: // Exit
                printf("\nExiting program...\n");
                if (myStack != NULL) {
                    freeStack(myStack);
                    printf("Stack memory freed\n");
                }
                if (myQueue != NULL) {
                    freeQueue(myQueue);
                    printf("Queue memory freed\n");
                }
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}