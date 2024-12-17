#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct CircularDoublyLinkedList {
    Node* last;
} CircularDoublyLinkedList;

void initList(CircularDoublyLinkedList* list) {
    list->last = NULL;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertAtEnd(CircularDoublyLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->last == NULL) {
        newNode->next = newNode->prev = newNode;
        list->last = newNode;
    } else {
        Node* first = list->last->next;
        newNode->next = first;
        newNode->prev = list->last;
        list->last->next = newNode;
        first->prev = newNode;
        list->last = newNode;
    }
}

void insertAtBeginning(CircularDoublyLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->last == NULL) {
        newNode->next = newNode->prev = newNode;
        list->last = newNode;
    } else {
        Node* first = list->last->next;
        newNode->next = first;
        newNode->prev = list->last;
        list->last->next = newNode;
        first->prev = newNode;
    }
}

void deleteValue(CircularDoublyLinkedList* list, int value) {
    if (list->last == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = list->last->next;

    do {
        if (current->data == value) {
            if (current == list->last->next && current == list->last) {
                list->last = NULL;
            } else if (current == list->last->next) {
                list->last->next = current->next;
                current->next->prev = list->last;
            } else if (current == list->last) {
                list->last = current->prev;
                current->prev->next = list->last->next;
                list->last->next->prev = list->last;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            printf("Deleted value: %d\n", value);
            return;
        }
        current = current->next;
    } while (current != list->last->next);

    printf("Value %d not found in the list.\n", value);
}

void display(CircularDoublyLinkedList* list) {
    if (list->last == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = list->last->next;
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != list->last->next);
    printf("(Back to Start)\n");
}

Node* search(CircularDoublyLinkedList* list, int value) {
    if (list->last == NULL) {
        return NULL;
    }

    Node* current = list->last->next;
    do {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    } while (current != list->last->next);

    return NULL;
}

int size(CircularDoublyLinkedList* list) {
    if (list->last == NULL) {
        return 0;
    }

    int count = 0;
    Node* current = list->last->next;
    do {
        count++;
        current = current->next;
    } while (current != list->last->next);

    return count;
}

int main() {
    CircularDoublyLinkedList list;
    initList(&list);

    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);
    printf("Circular Doubly Linked List: ");
    display(&list);

    insertAtBeginning(&list, 5);
    printf("After inserting at the beginning: ");
    display(&list);

    deleteValue(&list, 20);
    printf("After deleting 20: ");
    display(&list);

    Node* found = search(&list, 30);
    if (found) {
        printf("Value %d found in the list.\n", found->data);
    } else {
        printf("Value not found.\n");
    }

    printf("Size of the list: %d\n", size(&list));

    return 0;
}
