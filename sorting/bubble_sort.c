#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* number_list, int n) {
	int i, j, swapped;

	// Bubble Sort Algorithm
    for (i = 0; i < n-1; i++) {
    	swapped = 0;
    	for (j = 0; j < n-i-1; j++ ) {
    		if (number_list[j] > number_list[j+1]) {
    			// Arithmetic swap
    			number_list[j] += number_list[j+1];
    			number_list[j+1] = number_list[j] - number_list[j+1];
    			number_list[j] -= number_list[j+1];
    			swapped = 1;
    		}
    	}
    	if (!swapped) {
    		break;
    	}
    }
}

void print(int* number_list, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		printf("%d\n", number_list[i]);
    }
}