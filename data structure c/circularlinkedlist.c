
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularLinkedList {
    Node* last;
} CircularLinkedList;

void initList(CircularLinkedList* list) {
    list->last = NULL;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(CircularLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->last == NULL) {
        newNode->next = newNode;
        list->last = newNode;
    } else {
        newNode->next = list->last->next;
        list->last->next = newNode;
        list->last = newNode;
    }
}

void insertAtBeginning(CircularLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->last == NULL) {
        newNode->next = newNode;
        list->last = newNode;
    } else {
        newNode->next = list->last->next;
        list->last->next = newNode;
    }
}

void deleteValue(CircularLinkedList* list, int value) {
    if (list->last == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = list->last->next;
    Node* previous = list->last;

    do {
        if (current->data == value) {
            if (current == list->last->next && current == list->last) {
                list->last = NULL;
            } else if (current == list->last->next) {
                list->last->next = current->next;
            } else if (current == list->last) {
                previous->next = current->next;
                list->last = previous;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Deleted value: %d\n", value);
            return;
        }
        previous = current;
        current = current->next;
    } while (current != list->last->next);

    printf("Value %d not found in the list.\n", value);
}

void display(CircularLinkedList* list) {
    if (list->last == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = list->last->next;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list->last->next);
    printf("(Back to Start)\n");
}

Node* search(CircularLinkedList* list, int value) {
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

int size(CircularLinkedList* list) {
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
    CircularLinkedList list;
    initList(&list);

    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);
    printf("Circular Linked List: ");
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
