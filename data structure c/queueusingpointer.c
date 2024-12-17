#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initializeQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow. Cannot dequeue\n");
        return -1;
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->front->data;
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    Node* current = q->front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int countElements(Queue* q) {
    if (isEmpty(q)) {
        return 0;
    }
    int count = 0;
    Node* current = q->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    printf("Queue cleared successfully\n");
}

void reverseQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty. Cannot reverse\n");
        return;
    }
    Node *prev = NULL, *current = q->front, *next = NULL;
    q->rear = q->front;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    q->front = prev;
    printf("Queue reversed successfully\n");
}

int findElement(Queue* q, int value) {
    if (isEmpty(q)) {
        return -1;
    }
    int position = 1;
    Node* current = q->front;
    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

void mergeQueues(Queue* q1, Queue* q2) {
    if (q2->front == NULL) {
        return;
    }
    if (q1->rear == NULL) {
        q1->front = q2->front;
    } else {
        q1->rear->next = q2->front;
    }
    q1->rear = q2->rear;
    q2->front = q2->rear = NULL;
    printf("Queues merged successfully\n");
}

void menu() {
    printf("\nQueue Operations:\n");
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
    Queue q1, q2;
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
