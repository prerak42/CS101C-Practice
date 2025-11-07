#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to read the next word from the file
// Returns 1 if a word was read, 0 if EOF reached
int readWord(FILE *fp, char *buffer) {
    int c;
    int i = 0;

    // Skip non-alphabetic characters
    while ((c = fgetc(fp)) != EOF && !isalpha(c))
        ;

    // If EOF reached before any word, stop
    if (c == EOF)
        return 0;

    // Read the word
    do {
        buffer[i++] = tolower(c);  // store in lowercase
        c = fgetc(fp);
    } while (c != EOF && isalpha(c));

    buffer[i] = '\0';  // null-terminate
    return 1;
}

// Recursive function to count occurrences of the target word
int countWord(FILE *fp, const char *target) {
    char word[100];

    // Base case: if no more words, stop
    if (!readWord(fp, word))
        return 0;

    // If this word matches the target, count it
    if (strcmp(word, target) == 0)
        return 1 + countWord(fp, target);
    else
        return countWord(fp, target);
}

int main() {
    char filename[100];
    char target[100];
    FILE *fp;

    printf("Enter the file name: ");
    scanf("%s", filename);

    printf("Enter the word to search for: ");
    scanf("%s", target);

    // Convert target word to lowercase for case-insensitive comparison
    for (int i = 0; target[i]; i++)
        target[i] = tolower(target[i]);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int count = countWord(fp, target);

    printf("The word '%s' appears %d times in '%s'.\n", target, count, filename);

    fclose(fp);
    return 0;
}