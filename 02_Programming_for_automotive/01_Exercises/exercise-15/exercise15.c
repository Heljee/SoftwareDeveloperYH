/* 
Make a program to get a string from the standard input, then print the string to the output in the reversed order.

For examaple:

Enter a string: ABCDEF

Reversed string: FEDCBA
 */

#include <stdio.h>
#include <stdbool.h>

#define ARRAY_LENGTH 20

char *get_user_input_as_string();
char *reverse(char arr[]);
int length_of_string(char str[]);

/**
 * @brief Program start
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    char *user_input;
    user_input = get_user_input_as_string();
    user_input = reverse(user_input);
    printf("Reverse user input: %s\n", user_input);
    return 0;
}

/**
 * @brief Get the user input as string object
 * 
 * @return char* an string array with user input 
 */
char *get_user_input_as_string()
{
    static char arr[ARRAY_LENGTH];
    printf("ENTER ONE WORD: ");
    scanf("%s", arr);
    return arr;
}

/**
 * @brief Reverse elements in array
 * 
 * @param arr Array to reverse
 * @return char* Return array that is reversed
 */
char *reverse(char arr[])
{
    static char rev_array[ARRAY_LENGTH];
    int length = length_of_string(arr);
    int j = length - 1;
    for (int i = 0; i < length; i++)
    {
        rev_array[i] = arr[j];
        j--;
    }
    return rev_array;
}

/**
 * @brief Get actual length of string
 * 
 * @param str String[] to analyse
 * @return int Real length of array
 */
int length_of_string(char str[])
{
    int count = 0;
    //finding the length of the string
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}