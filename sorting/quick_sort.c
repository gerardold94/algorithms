#include <stdio.h>
#include <stdlib.h>

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

void quicksort(int* number_list, int start, int end) {
    int pivot;

    if (start < end) {
        pivot = divide(number_list, start, end);

        // Sort the list of minors
        quicksort(number_list, start, pivot - 1);
        // Sort the list of biggest
        quicksort(number_list, pivot + 1, end);
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
    quicksort(number_list, 0, n-1);
    print(number_list, n);

    free (number_list); // free memory

    return 0;
}
