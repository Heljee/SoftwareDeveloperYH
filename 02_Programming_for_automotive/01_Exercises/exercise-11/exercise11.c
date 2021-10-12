#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool input_is_within_range(int number)
{
    return (number >= 0 && number <= 255);
}

int get_user_input()
{
    int number;
    printf("Enter number between 0-255: ");
    scanf("%d", &number);
    return number;
}

void decimal_to_binary(int num)
{
    printf("binary representation of %d: ", num);
    for (int i = 7; i >= 0; i--)
    {
        int k = num >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
}

int main(void)
{
    int number = 256;
    while (!input_is_within_range(number))
    {
        number = get_user_input();
    }
    decimal_to_binary(number);
    return 0;
}
