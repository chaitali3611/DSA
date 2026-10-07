#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    char* result = (char*)malloc(5000 * sizeof(char));
    strcpy(result, "1");

    for (int k = 1; k < n; k++) {
        char* next = (char*)malloc(5000 * sizeof(char));
        int i = 0;
        int j = 0;

        while (result[i] != '\0') {
            char digit = result[i];
            int count = 0;

            // Count consecutive same digits
            while (result[i] == digit) {
                count++;
                i++;
            }

            // Add count
            if (count >= 10) {
                next[j++] = (count / 10) + '0';
                next[j++] = (count % 10) + '0';
            } else {
                next[j++] = count + '0';
            }

            // Add digit
            next[j++] = digit;
        }

        next[j] = '\0';

        free(result);
        result = next;
    }

    return result;
}