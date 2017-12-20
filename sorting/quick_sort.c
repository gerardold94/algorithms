#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

int divide(int* number_list, int start, int end) {
    int left;
    int right;
    int pivot;

    pivot = number_list[start];
    left = start;
    right = end;

    // While the indexes are not crossed
    while (left < right) {
        while (number_list[right] > pivot) {
            right--;
        }

        while ((left < right) && (number_list[left] <= pivot)) {
            left++;
        }

        // If the indexes are not crossed yet, we continue swapping
        if (left < right) {
            // Arithmetic swap
            number_list[left] += number_list[right];
            number_list[right] = number_list[left] - number_list[right];
            number_list[left] -= number_list[right];
        }
    }

    // If the indexes cross, we put the pivot in the right place
    number_list[right] += number_list[start];
    number_list[start] = number_list[right] - number_list[start];
    number_list[right] -= number_list[start];

    // New position for pivot
    return right;
}

void quickSort(int* number_list, int start, int end) {
    int pivot;

    if (start < end) {
        pivot = divide(number_list, start, end);

        // Sort the list of minors
        quickSort(number_list, start, pivot - 1);
        // Sort the list of biggest
        quickSort(number_list, pivot + 1, end);
    }
}

void print(int* number_list, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		printf("%d\n", number_list[i]);
    }
}