#include "interpolation_search.h"

/**
 * Search for a number in a sorted list of integers
 * @param  list   list of integers
 * @param  target number to search
 * @param  size   length of the list
 * @return        index of target
 */
int search(int* list, int target, int n) {
    // Indexes of the corners
    int lowCorner = 0, highCorner = (n - 1);

    // Since array is sorted, the element
    // must be in range defined by corner
    while (
    	lowCorner <= highCorner &&
    	target >= list[lowCorner] &&
    	target <= list[highCorner]) {
        int pos = lowCorner + (( (float)(highCorner-lowCorner) /
              (list[highCorner]-list[lowCorner]) ) * (target - list[lowCorner]));

        // Target found
        if (list[pos] == target)
            return pos;

        // If target is larger, target is in upper part
        if (list[pos] < target)
            lowCorner = pos + 1;
        // If target is smaller, target is in lower part
        else
            highCorner = pos - 1;
    }
    return -1;
}