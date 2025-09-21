#include<stdio.h>
#include<math.h>
void digitCountSum(int number, int *count, int *sum);

int main() {
    int number, count = 0, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    digitCountSum(number, &count, &sum);

    printf("Number of digits: %d\n", count);
    printf("Sum of digits: %d\n", sum);

    return 0;
}

void digitCountSum(int number, int *count, int *sum) {
    while (number != 0) {
        *sum += number % 10;
        *count += 1;
        number /= 10;
    }
}
