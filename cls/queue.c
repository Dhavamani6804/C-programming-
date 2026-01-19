#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Queue with linked list implementation
 
typedef struct Node {
    int Data;
    struct Node* Next;
}Node;
 
typedef struct Queue {
    Node* Front;
    Node* Rear;
    int QueueSize;
}Queue;
 
Node* CreateNode(int Data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->Data = Data;
    newNode->Next = NULL;
    return newNode;
}
 
Queue* CreateQueue() {
    Queue *MyQueue = (Queue*)malloc(sizeof(Queue));
    if (!MyQueue) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    //initialize the queue with default values
    MyQueue->Front = NULL;
    MyQueue->Rear = NULL;
    MyQueue->QueueSize = 0;
    return MyQueue;
}
 
bool enqueue(Queue* MyQueue, int Data) {
    Node* newNode = CreateNode(Data);
    if (MyQueue->Rear == NULL) {
        MyQueue->Front = newNode;
        MyQueue->Rear = newNode;
    } else {
        MyQueue->Rear->Next = newNode;
        MyQueue->Rear = newNode;
    }
    MyQueue->QueueSize++;
    return true;
}
 
 
bool IsQueueEmpty(Queue* MyQueue) {
    return MyQueue->QueueSize == 0;
}
 
int Dequeue(Queue* MyQueue) {
    if (IsQueueEmpty(MyQueue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return false;
    }
    Node* temp = MyQueue->Front;
    int Data = temp->Data;
    MyQueue->Front = MyQueue->Front->Next;
    if (MyQueue->Front == NULL) {
        MyQueue->Rear = NULL;
    }
    free(temp);
    MyQueue->QueueSize--;
    return Data;
}
 
int QueuePeek(Queue* MyQueue) {
    if (IsQueueEmpty(MyQueue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1; // Indicate that the queue is empty
    }
    return MyQueue->Front->Data;
}
 
int main() {
    Queue* MyQueue = CreateQueue();
    if(enqueue(MyQueue, 10)) {
        printf("Enqueued new data to the queue.\n" );
    }
    enqueue(MyQueue, 20);
    enqueue(MyQueue, 30);
    enqueue(MyQueue, 40);
    printf("Size of Queue: %d\n", MyQueue->QueueSize);
    printf ("Dequeue value %d\n", Dequeue(MyQueue) );
    printf("Size of Queue after one dequeue: %d\n", MyQueue->QueueSize);
    printf ("Dequeue value %d\n", Dequeue(MyQueue) );
    printf("Peek value %d\n", QueuePeek(MyQueue) );
    return 0;
}