#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct CircularQueue {
    int data[MAX];
    int front;
    int rear;
    int size;
} CircularQueue;

void initializeQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int isFull(CircularQueue *q) {
    return q->size == MAX;
}

int isEmpty(CircularQueue *q) {
    return q->size == 0;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow. Cannot add %d\n", value);
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->size++;
    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow. Cannot dequeue\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    if (q->size == 0) {
        q->front = -1;
        q->rear = -1;
    }
    return value;
}

int peek(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->data[q->front];
}

void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0, index = q->front; i < q->size; i++, index = (index + 1) % MAX) {
        printf("%d ", q->data[index]);
    }
    printf("\n");
}

int countElements(CircularQueue *q) {
    return q->size;
}

void clearQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    printf("Queue cleared successfully\n");
}

void reverseQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty. Cannot reverse\n");
        return;
    }
    for (int i = 0; i < q->size / 2; i++) {
        int index1 = (q->front + i) % MAX;
        int index2 = (q->front + q->size - 1 - i) % MAX;
        int temp = q->data[index1];
        q->data[index1] = q->data[index2];
        q->data[index2] = temp;
    }
    printf("Queue reversed successfully\n");
}

int findElement(CircularQueue *q, int value) {
    for (int i = 0, index = q->front; i < q->size; i++, index = (index + 1) % MAX) {
        if (q->data[index] == value) return i + 1;
    }
    return -1;
}

void mergeQueues(CircularQueue *q1, CircularQueue *q2) {
    if (q2->size == 0) return;
    for (int i = 0, index = q2->front; i < q2->size; i++, index = (index + 1) % MAX) {
        enqueue(q1, q2->data[index]);
    }
    clearQueue(q2);
    printf("Queues merged successfully\n");
}

void menu() {
    printf("\nCircular Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display Queue\n");
    printf("5. Count Elements\n");
    printf("6. Clear Queue\n");
    printf("7. Reverse Queue\n");
    printf("8. Find Element\n");
    printf("9. Merge Queues\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    CircularQueue q1, q2;
    initializeQueue(&q1);
    initializeQueue(&q2);
    int choice, value, position;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q1, value);
                break;
            case 2:
                value = dequeue(&q1);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                value = peek(&q1);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                displayQueue(&q1);
                break;
            case 5:
                printf("Number of elements in the queue: %d\n", countElements(&q1));
                break;
            case 6:
                clearQueue(&q1);
                break;
            case 7:
                reverseQueue(&q1);
                break;
            case 8:
                printf("Enter the value to find: ");
                scanf("%d", &value);
                position = findElement(&q1, value);
                if (position == -1) {
                    printf("Element not found in the queue\n");
                } else {
                    printf("Element found at position: %d\n", position);
                }
                break;
            case 9:
                printf("Enter elements for second queue (enter -1 to stop): ");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1) break;
                    enqueue(&q2, value);
                }
                mergeQueues(&q1, &q2);
                break;
            case 10:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
