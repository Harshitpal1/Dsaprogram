#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int next[MAX_SIZE];
    int head;
    int freeIndex;
} ArrayLinkedList;

void initList(ArrayLinkedList *list) {
    list->head = -1;
    list->freeIndex = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        list->next[i] = -1;
    }
}

void insert(ArrayLinkedList *list, int value) {
    if (list->freeIndex >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }
    int newIndex = list->freeIndex;
    list->data[newIndex] = value;
    list->next[newIndex] = -1;
    if (list->head == -1) {
        list->head = newIndex;
    } else {
        int current = list->head;
        while (list->next[current] != -1) {
            current = list->next[current];
        }
        list->next[current] = newIndex;
    }
    list->freeIndex++;
}

void deleteValue(ArrayLinkedList *list, int value) {
    int current = list->head;
    int previous = -1;
    while (current != -1) {
        if (list->data[current] == value) {
            if (previous == -1) {
                list->head = list->next[current];
            } else {
                list->next[previous] = list->next[current];
            }
            list->next[current] = -1;
            return;
        }
        previous = current;
        current = list->next[current];
    }
    printf("Value %d not found in the list.\n", value);
}

void display(ArrayLinkedList *list) {
    int current = list->head;
    while (current != -1) {
        printf("%d -> ", list->data[current]);
        current = list->next[current];
    }
    printf("NULL\n");
}

int search(ArrayLinkedList *list, int value) {
    int current = list->head;
    while (current != -1) {
        if (list->data[current] == value) {
            return current;
        }
        current = list->next[current];
    }
    return -1;
}

int main() {
    ArrayLinkedList list;
    initList(&list);

    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    display(&list);

    deleteValue(&list, 20);
    display(&list);

    insert(&list, 40);
    display(&list);

    int value = 30;
    int index = search(&list, value);
    if (index != -1) {
        printf("Value %d found at index %d\n", value, index);
    } else {
        printf("Value %d not found in the list\n", value);
    }

    return 0;
}

