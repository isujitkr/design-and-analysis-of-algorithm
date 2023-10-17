
#include <stdio.h>
#include <string.h>

#define D 256 // Number of characters in the alphabet

void searchRabinKarp(char *pattern, char *text, int q) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int pHash = 0; // Hash value for pattern
    int tHash = 0; // Hash value for text
    int h = 1;    // Hash multiplier

    // The value of h would be "pow(D, M-1) % q"
    for (i = 0; i < M - 1; i++)
        h = (h * D) % q;

    // Calculate the hash value of the pattern and the first window of the text
    for (i = 0; i < M; i++) {
        pHash = (D * pHash + pattern[i]) % q;
        tHash = (D * tHash + text[i]) % q;
    }

    // Slide the pattern over the text one by one
    for (i = 0; i <= N - M; i++) {
        // Check if the hash values match
        if (pHash == tHash) {
            // If the hash values match, check character by character
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate the hash value for the next window of text
        if (i < N - M) {
            tHash = (D * (tHash - text[i] * h) + text[i + M]) % q;
            if (tHash < 0)
                tHash += q; // Ensure tHash is positive
        }
    }
}

int main() {
    char text[1000];
    char pattern[100];
    int q = 101; // A prime number for the hash function

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern to search for: ");
    scanf("%s", pattern);

    searchRabinKarp(pattern, text, q);

    return 0;
}
