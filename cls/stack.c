#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Stack with linked list implementation
 
typedef struct Node {
    int Data;
    struct Node* Next;
}Node;
 
 
typedef struct Stack {
    Node* Top;
    int Size;
}Stack;
 
Stack* CreateStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->Top = NULL;
    stack->Size = 0;
    return stack;
}
 
bool StackPush (Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        return false; // Memory allocation failed
    }
    newNode->Data = data;
    newNode->Next = stack->Top;
    stack->Top = newNode;
    stack->Size++;
    return true;
}
 
int StackPop (Stack* stack) {
    if (stack->Size == 0) {
        return -1; // Stack is empty
    }
    Node* temp = stack->Top;
    int poppedData = temp->Data;
    stack->Top = stack->Top->Next;
    free(temp);
    stack->Size--;
    return poppedData;
}
 
int StackPeep (Stack* stack) {
    if (stack->Size == 0) {
        return -1; // Stack is empty
    }
    return stack->Top->Data;
}
 
int main() {
    Stack* myStack = CreateStack();
    StackPush(myStack, 10);
    StackPush(myStack, 20);
    StackPush(myStack, 30);
    printf("Popped: %d\n", StackPop(myStack)); // Should print 30
    printf("Top element: %d\n", StackPeep(myStack)); // Should print 20
    return 0;
}