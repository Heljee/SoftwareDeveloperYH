#include <stdio.h>
#include <stdbool.h>

int get_last_digit(int number)
{
    return number % 10;
}

bool evaluate_input(int number)
{
    return ((0 <= number) && (number <= 1000));
}

int main(void)
{
    int last_digit, number=-1;

    // Get user input
    while (!evaluate_input(number))
    {
        printf("Enter a number from 0-1000: ");
        scanf("%d", &number);
    }

    // Print all numbers ending with 7
    printf("\nNumbers with 7 in the end: ");
    do
    {
        last_digit = get_last_digit(number);
        last_digit == 7 && printf("%d ", number);
        number = number / 10;
    } while (number != 0);

    return 0;
}
