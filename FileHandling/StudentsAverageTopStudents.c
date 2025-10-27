#include<stdio.h>

int main(){
    FILE *fin, *fout;
    int count = 0;
    char name[50];
    float score, total = 0.0, average;

    fin = fopen("students.txt", "r");
    if(fin == NULL){
        printf("Error opening students.txt\n");
        return 1;
    }

    while(fscanf(fin, "%s %f", name, &score) == 2){
        total += score;
        count++;
    }

    if(count > 0){
        average = total / count;
        printf("Average score: %.2f\n", average);
    } else {
        printf("No valid scores found.\n");
    }

    fout = fopen("top_students.txt", "w");
    if(fout == NULL){
        printf("Error creating top_students.txt\n");
        fclose(fin);
        return 1;
    }

    rewind(fin);
    while(fscanf(fin, "%s %f", name, &score) == 2){
        if(score > average){
            fprintf(fout, "%s %.2f\n", name, score);
        }
    }

    fclose(fout);
    fclose(fin);
    return 0;
}