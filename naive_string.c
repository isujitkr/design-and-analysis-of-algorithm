
#include <stdio.h>
#include <string.h>

int naiveStringMatch(char *text, char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;

        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patternLen) {
            return i; // Pattern found at index i in the text
        }
    }

    return -1; // Pattern not found in the text
}

int main() {
    char text[100];
    char pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern to search for: ");
    scanf("%s", pattern);

    int position = naiveStringMatch(text, pattern);

    if (position != -1) {
        printf("Pattern found at position %d in the text.\n", position);
    } else {
        printf("Pattern not found in the text.\n");
    }

    return 0;
}
