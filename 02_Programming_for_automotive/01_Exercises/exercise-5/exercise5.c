#include <stdio.h>

// Exercise 5.1
// Convert to binary and hexadecimal
void convert_to_binary(int num)
{
    int reminder[10], i;
    for (i = 0; num > 0; i++)
    {
        reminder[i] = num % 2;
        num = num / 2;
    }

    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", reminder[i]);
    }
    return;
}

int main(void)
{
    convert_to_binary(-13);
    return 0;
}
