#include "jump_search.h"
#include <math.h>

/**
 * Search for a number in a list of integers
 * @param  list   list of integers
 * @param  target number to search
 * @param  size   length of the list
 * @return        index of target
 */
int search(int list[], int target, int size) {
	// Block size to be jumped
	int step = sqrt(size);

	// Finding the block where element is present
	int prev = 0;
	while (list[(int)min(step, size)-1] < target)
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size) // It is not present
            return -1;
    }

    // Linear search for target in block
    while (list[prev] < target)
    {
        prev++;
        // If we reached next block or end of
        // list, element is not present.
        if (prev == min(step, size))
            return -1;
    }
    // If element is found
    if (list[prev] == target)
        return prev;

    return -1;
}

int min(int a, int b) {
	return a < b ? a : b;
}