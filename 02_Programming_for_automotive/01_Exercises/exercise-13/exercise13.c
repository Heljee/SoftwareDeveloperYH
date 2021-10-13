#include <stdio.h>
#include <stdbool.h>

int get_number();
int sum_numbers(int number);
int get_last_digit(int number);
bool check_if_even(int digit);

int main(int argc, char const *argv[])
{
    int number = get_number();
    int sum = sum_numbers(number);
    printf("Sum of all numbers: %d", sum);
    return 0;
}

int sum_numbers(int number)
{
    int sum = 0;
    int last_digit;
    do
    {
        last_digit = get_last_digit(number);
        if (check_if_even(last_digit))
        {
            sum += get_last_digit(number);
        }
        number /= 10;
    } while (number != 0);
    return sum;
}

int get_number()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    return number;
}

int get_last_digit(int number)
{
    return number % 10;
}

bool check_if_even(int digit) {
    return digit % 2 == 0;
}
