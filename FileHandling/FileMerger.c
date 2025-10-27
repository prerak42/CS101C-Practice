#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 256

int main() {
    FILE *f1, *f2, *fout;
    char line1[MAX_LINE], line2[MAX_LINE];

    // Open input files
    f1 = fopen("file1.txt", "r");
    f2 = fopen("file2.txt", "r");
    fout = fopen("merged.txt", "w");

    if (f1 == NULL || f2 == NULL || fout == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    // Read lines alternately from both files
    while (1) {
        char *res1 = fgets(line1, MAX_LINE, f1);
        char *res2 = fgets(line2, MAX_LINE, f2);

        if (res1 != NULL)
            fputs(line1, fout);

        if (res2 != NULL)
            fputs(line2, fout);

        if (res1 == NULL && res2 == NULL)
            break;
    }

    printf("Files merged successfully into merged.txt\n");

    fclose(f1);
    fclose(f2);
    fclose(fout);

    return 0;
}