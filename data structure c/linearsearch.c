#include <stdio.h>
#include <string.h>

void linearSearch(char arr[][100], int size, char target[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found in the array.\n");
}

int main() {
    int size;
    char target[100];

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    char arr[size][100];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%s", arr[i]);
    }

    printf("Enter the string to search: ");
    scanf("%s", target);

    linearSearch(arr, size, target);

    return 0;
}
