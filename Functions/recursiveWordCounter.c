#include <stdio.h>
#include <ctype.h>

// Recursive function to count words
int countWords(FILE *fp, int inWord) {
    int c = fgetc(fp);

    // Base case: End of file
    if (c == EOF)
        return 0;

    // If it's a letter or digit, we are inside a word
    if (isalnum(c)) {
        if (!inWord) {
            // We just entered a new word
            return 1 + countWords(fp, 1);
        } else {
            // Still in the same word
            return countWords(fp, 1);
        }
    } else {
        // Not a letter/digit → outside a word
        return countWords(fp, 0);
    }
}

int main() {
    char filename[100];
    FILE *fp;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    int totalWords = countWords(fp, 0);
    printf("Total words in '%s': %d\n", filename, totalWords);

    fclose(fp);
    return 0;
}