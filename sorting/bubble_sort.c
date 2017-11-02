#include <stdio.h>
#include <stdlib.h>

void sort(int* number_list, int n) {
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

int main(int argc, char *argv[]) {
    int number, n, i, j;
    int* number_list;

    // Read n - len of data
    scanf ("%d", &n);
    number_list = malloc (sizeof(int)*n);

   	// Read data from stdin
    for (i = 0; i < n; i++) {
		scanf("%d", &number_list[i]);
    }

    // Pass number_list by reference
    sort(number_list, n);
    print(number_list, n);

    free (number_list); // free memory

    return 0;
}
