#include <stdio.h>

int main() {
    FILE *fp_in, *fp_out;
    int id, count = 0;
    char name[50];
    float marks, total = 0.0, average;

    // Open the input file
    fp_in = fopen("students.txt", "r");
    if (fp_in == NULL) {
        printf("Error opening students.txt\n");
        return 1;
    }

    // Read all student records using fscanf()
    while (fscanf(fp_in, "%d %s %f", &id, name, &marks) == 3) {
        total += marks;
        count++;
    }

    fclose(fp_in);

    if (count == 0) {
        printf("No student records found.\n");
        return 1;
    }

    // Calculate average
    average = total / count;

    // Open the output file
    fp_out = fopen("report.txt", "w");
    if (fp_out == NULL) {
        printf("Error creating report.txt\n");
        return 1;
    }

    // Write the result to the output file
    fprintf(fp_out, "Total Students: %d\n", count);
    fprintf(fp_out, "Average Marks: %.1f\n", average);

    fclose(fp_out);

    printf("Report generated successfully in report.txt\n");
    return 0;
}