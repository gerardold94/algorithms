#include <stdlib.h>
#include <math.h>

int search(int* number_list, int target, int n) {
    int min = 0;
    int max = n - 1;
    int guess;

    while(max >= min) {
        guess = floor((max+min) / 2);
        if (number_list[guess] == target) return guess;
        else if (number_list[guess] < target) min = guess + 1;
        else max = guess - 1;
    }

    return -1;
}
