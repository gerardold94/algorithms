#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(int* number_list, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("%d ", number_list[i]);
    }
    printf("\n");
}

void merge(int* number_list, int start, int pivot, int end) {
    int *lowHalf, *highHalf;
    int i, j, k;
    int lowSize = pivot-start+1;
    int highSize = end-pivot;
    lowHalf = malloc(sizeof(int)*lowSize);
    highHalf = malloc(sizeof(int)*highSize);

    k = start;
    for (i = 0; k <= pivot; i++, k++) lowHalf[i] = number_list[k];
    for (j = 0; k <= end; j++, k++) highHalf[j] = number_list[k];

    k = start;
    i = 0;
    j = 0;

    while (i < lowSize && j < highSize) {
        if (lowHalf[i] < highHalf[j]) number_list[k] = lowHalf[i++];
        else number_list[k] = highHalf[j++];
        k++;
    }

    while (i < lowSize) number_list[k++] = lowHalf[i++];

    while (j < highSize) number_list[k++] = highHalf[j++];
}

void mergeSort(int* number_list, int start, int end) {
    int pivot;

    if (start < end) {
        pivot = floor((start+end) / 2);
        // Sort the list of minors
        mergeSort(number_list, start, pivot);
        // Sort the list of biggest
        mergeSort(number_list, pivot + 1, end);

        // Merge subarrays
        merge(number_list, start, pivot, end);
    }
}