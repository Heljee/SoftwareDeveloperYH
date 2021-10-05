#include <stdio.h>

#define NAME ("\x84 Heljee")

/**
 * @brief Define a preprocessor macro and print name
 * 
 * @return int end app
 */
int main(void)
{
    printf("%s", NAME);
    return 0;
}
