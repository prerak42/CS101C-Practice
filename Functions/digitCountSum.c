#include<stdio.h>
#include<math.h>
void digitCountSum(int number, int *count, int *sum);        //used pointers as dereferencing allows the function to change the values directly in 'main'

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
        *sum += number % 10;        //add the last digit
        *count += 1;        //counter for the number of digits
        number /= 10;        //chopping off the last digit till it becomes 0 to exit the 'while' loop
    }
}
