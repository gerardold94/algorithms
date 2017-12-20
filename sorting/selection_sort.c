#include <stdio.h>
#include <stdlib.h>

void print(int* number_list, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("%d ", number_list[i]);
    }
    printf("\n");
}

int indexOfMinimum(int* number_list, int startIndex, int n) {
    int minValue = number_list[startIndex];
    int minIndex = startIndex;
    int i;

    for (i = minIndex + 1; i < n; i++) {
        if (number_list[i] < minValue) {
            minIndex = i;
            minValue = number_list[i];
        }
    }
    return minIndex;
}

void selectionSort(int* number_list, int n) {
    int min, i, tmp;
    for (i = 0; i < n-1; i++) {
        min = indexOfMinimum(number_list, i, n);
        // Swap min to the correct position
        tmp = number_list[min];
        number_list[min] = number_list[i];
        number_list[i] = tmp;
    }
}