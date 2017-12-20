#include "max_occuring_char.h"
#include <string.h>

#define SIZE 256

char getMaxOccuringChar(char* str) {
	// Array to keep the count of individual characters (Hash)
    int count[SIZE] = {0};

    // Fill character count array
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        count[str[i]]++;

    int max = -1;
    short result;

    // Find max in the count array
    for (int i = 0; i < len; i++) {
        if (max < count[str[i]]) {
            max = count[str[i]];
            result = i;
        }
    }

    return str[result];
}