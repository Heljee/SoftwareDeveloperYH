/* 
Make a program to fill a 10-element int array with random numbers, then

print the array to the output.
sort the array ascending and then
Print the sorted array to the output.
To generate random numbers, you can use srand and rand functions in stdlib.h and the time function in time.h.

 

For example:

The array filled with random numbers: {9, 3, 8, 0, 5, 2, 6, 7, 1, 4}

The sorted array: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } 
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void generate_random_array(int array[]);
void print_array(int array[]);
void sort_ascending(int array[]);
void sort_descending(int array[]);

int main(int argc, char const *argv[])
{
    int array[ARRAY_SIZE] = {0};
    generate_random_array(array);
    printf("RANDOM NUMBERS:\n");
    print_array(array);

    printf("\nASCENDING ORDER:\n");
    sort_ascending(array);
    print_array(array);

    printf("\nDESCENDING ORDER:\n");
    sort_descending(array);
    print_array(array);
    
    return 0;
}

void generate_random_array(int array[ARRAY_SIZE])
{
    time_t seconds = time(NULL);
    srand(seconds);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand() % 10;
    }
}

void print_array(int array[ARRAY_SIZE])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d, ", array[i]);
    }
}

void sort_ascending(int array[])
{
    int temp = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = i + 1; j < ARRAY_SIZE; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
void sort_descending(int array[])
{
    int temp = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = i + 1; j < ARRAY_SIZE; j++)
        {
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
