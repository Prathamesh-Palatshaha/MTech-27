#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20 

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear; 
    int size;
} Queue;

void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

int isFull(Queue *q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Error: Queue is full.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    q->size++;
}

// Function to remove an element from the front of the queue (Dequeue)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty.\n");
        return -1; // Return an error value
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return item;
}

// Function to get the front element without removing it (Peek)
int peek(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->items[q->front];
}

// Function to print the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("[ ]\n");
        return;
    }
    printf("[ ");
    int count = 0;
    int i = q->front;
    while (count < q->size) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    printf("] (Front to Rear)\n");
}

void mergeQueues(Queue *q1, Queue *q2, Queue *resultQ) {
    initializeQueue(resultQ);
    printf("\n--- Merging Process ---\n");
    
    while (!isEmpty(q1) && !isEmpty(q2)) {
        int val1 = peek(q1);
        int val2 = peek(q2);

        if (val1 <= val2) {
            // Take from Q1
            enqueue(resultQ, dequeue(q1));
            printf("  -> Enqueued %d from Q1\n", val1);
        } else {
            // Take from Q2
            enqueue(resultQ, dequeue(q2));
            printf("  -> Enqueued %d from Q2\n", val2);
        }
    }

    // 3. Empty the remaining elements from Q1 (if any)
    while (!isEmpty(q1)) {
        int val = dequeue(q1);
        enqueue(resultQ, val);
        printf("  -> Enqueued %d from remaining Q1\n", val);
    }

    // 4. Empty the remaining elements from Q2 (if any)
    while (!isEmpty(q2)) {
        int val = dequeue(q2);
        enqueue(resultQ, val);
        printf("  -> Enqueued %d from remaining Q2\n", val);
    }
    
    printf("--- Merge Complete ---\n");
}

// --- Main Function ---
int main() {
    // Declare the queues
    Queue q1, q2, resultQ;
    
    // Initialize
    initializeQueue(&q1);
    initializeQueue(&q2);

    // Populate Queue 1 with sorted data
    enqueue(&q1, 10);
    enqueue(&q1, 30);
    enqueue(&q1, 50);
    enqueue(&q1, 70);

    // Populate Queue 2 with sorted data
    enqueue(&q2, 20);
    enqueue(&q2, 40);
    enqueue(&q2, 60);
    enqueue(&q2, 80);
    enqueue(&q2, 90);
    
    printf("Queue 1 (Sorted): ");
    printQueue(&q1);
    
    printf("Queue 2 (Sorted): ");
    printQueue(&q2);

    // Perform the merge
    mergeQueues(&q1, &q2, &resultQ);

    printf("\n\nResult Queue (Merged and Sorted): ");
    printQueue(&resultQ);
    
    printf("\nQueue 1 After Merge (Should be empty): ");
    printQueue(&q1);
    printf("Queue 2 After Merge (Should be empty): ");
    printQueue(&q2);

    return 0;
}