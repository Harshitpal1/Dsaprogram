#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void initList(LinkedList* list) {
    list->head = NULL;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert(LinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteValue(LinkedList* list, int value) {
    Node* current = list->head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Value %d not found in the list.\n", value);
}

void display(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* search(LinkedList* list, int value) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int size(LinkedList* list) {
    int count = 0;
    Node* current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    LinkedList list;
    initList(&list);

    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    printf("List after insertion: ");
    display(&list);

    deleteValue(&list, 20);
    printf("List after deletion: ");
    display(&list);

    int searchValue = 30;
    Node* foundNode = search(&list, searchValue);
    if (foundNode) {
        printf("Value %d found in the list.\n", searchValue);
    } else {
        printf("Value %d not found in the list.\n", searchValue);
    }

    printf("Size of the list: %d\n", size(&list));

    return 0;
}
