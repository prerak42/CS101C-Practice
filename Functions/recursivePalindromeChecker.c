/*
 * Recursive Palindrome Checker and String Reverser
 * This program checks if a given string is a palindrome using recursion.
 * It also reverses the string using recursion.
*/

#include<stdio.h>

int isPalindrome(char str[], int start, int end) {
    // Base case: If there is only one character or no characters
    if (start >= end) {
        return 1; // True
    }
    // If first and last characters do not match
    if (str[start] != str[end]) {
        return 0; // False
    }
    // Move towards the middle
    return isPalindrome(str, start + 1, end - 1);
}

void reversedString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }
    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    // Recur for the next pair
    reversedString(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    if (isPalindrome(str, 0, length - 1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    printf("Reversed string: ");
    reversedString(str, 0, length - 1);
    printf("%s\n", str);

    return 0;
}