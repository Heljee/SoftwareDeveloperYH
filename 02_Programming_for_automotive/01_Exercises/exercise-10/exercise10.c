#include <stdio.h>
#include <stdbool.h>

bool user_input_is_correct(int number)
{
    return ((number >= 2) && (number <= 10000));
}

int get_user_input()
{
    int number;
    do
    {
        printf("Enter int from 2 - 10 000: ");
        scanf("%d", &number);
    } while (!user_input_is_correct(number));
    return number;
}

int main(void)
{
    int number;
    bool isPrime = true;
    number = get_user_input();

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            isPrime = false;
            break;
        }
    };

    printf("%d is prime: %s", number , isPrime ? "true" : "false");
    return 0;
}
