#include <stdio.h>
#include <string.h>

void binarySearch(char arr[][100], int size, char target[]) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        int comparison = strcmp(arr[mid], target);

        if (comparison == 0) {
            printf("Element found at index %d\n", mid);
            return;
        }

        if (comparison < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Element not found in the array.\n");
}

void bubbleSort(char arr[][100], int size) {
    char temp[100];
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
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

    bubbleSort(arr, size);

    printf("Enter the string to search: ");
    scanf("%s", target);

    binarySearch(arr, size, target);

    return 0;
}