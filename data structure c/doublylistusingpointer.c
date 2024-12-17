#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

void initList(DoublyLinkedList* list) {
    list->head = NULL;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(DoublyLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void displayForward(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void displayBackward(DoublyLinkedList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("NULL\n");
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

void deleteValue(DoublyLinkedList* list, int value) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Deleted value: %d\n", value);
            return;
        }
        current = current->next;
    }
    printf("Value %d not found in the list.\n", value);
}

Node* search(DoublyLinkedList* list, int value) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int size(DoublyLinkedList* list) {
    int count = 0;
    Node* current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    DoublyLinkedList list;
    initList(&list);

    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    printf("Forward: ");
    displayForward(&list);
    printf("Backward: ");
    displayBackward(&list);

    deleteValue(&list, 20);
    printf("After deletion:\n");
    printf("Forward: ");
    displayForward(&list);
    printf("Backward: ");
    displayBackward(&list);

    insert(&list, 40);
    insert(&list, 50);
    printf("After insertion:\n");
    printf("Forward: ");
    displayForward(&list);
    printf("Backward: ");
    displayBackward(&list);

    Node* found = search(&list, 30);
    if (found) {
        printf("Value %d found in the list.\n", found->data);
    } else {
        printf("Value not found.\n");
    }

    printf("Size of the list: %d\n", size(&list));

    return 0;
}
