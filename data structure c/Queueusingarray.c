#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Queue {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow. Cannot add %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow. Cannot dequeue\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->data[q->front];
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int countElements(Queue *q) {
    if (isEmpty(q)) {
        return 0;
    }
    return q->rear - q->front + 1;
}

void clearQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
    printf("Queue cleared successfully\n");
}

void menu() {
    printf("\nQueue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display Queue\n");
    printf("5. Count Elements\n");
    printf("6. Clear Queue\n");
    printf("7. Check if Queue is Empty\n");
    printf("8. Check if Queue is Full\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Queue q;
    initializeQueue(&q);
    int choice, value;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                displayQueue(&q);
                break;
            case 5:
                printf("Number of elements in the queue: %d\n", countElements(&q));
                break;
            case 6:
                clearQueue(&q);
                break;
            case 7:
                if (isEmpty(&q)) {
                    printf("Queue is Empty\n");
                } else {
                    printf("Queue is not Empty\n");
                }
                break;
            case 8:
                if (isFull(&q)) {
                    printf("Queue is Full\n");
                } else {
                    printf("Queue is not Full\n");
                }
                break;
            case 9:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
