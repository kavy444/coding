#include <stdio.h>

int main() {
    int a, b, c;

    // Prompt and read the first number
    printf("Enter the first number: ");
    scanf("%d", &a);

    // Prompt and read the second number
    printf("Enter the second number: ");
    scanf("%d", &b);

    // Prompt and read the third number
    printf("Enter the third number: ");
    scanf("%d", &c);

    // Check if 'a' is even
    if (a % 2 == 0) {
        printf("a is even.\n");

        // Check if 'a' is the largest number
        if (a > b && a > c) {
            printf("a is the largest number.\n");
        } else {
            printf("a is not the largest number.\n");
        }
    } else {
        // If 'a' is not even, print the sum of the numbers
        printf("a is not even. The sum of the numbers is %d.\n", a + b + c);
    }

    return 0;
}