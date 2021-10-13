#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define NAME_MAX_LENGTH 32

bool is_lowercase(char character)
{
    return (character >= 97 && character <= 122);
}

bool is_uppercase(char character)
{
    return (character >= 65 && character <= 90);
}

bool is_letter(char character)
{
    return (is_lowercase(character) || is_uppercase(character));
}

bool is_whitespace(char character)
{
    return character == 32;
}

char convert_lowercase_to_uppercase(char character)
{
    return character - ('a' - 'A');
}

char convert_uppercase_to_lowercase(char character)
{
    return character + ('a' - 'A');
}

int main(void)
{
    char user_input[NAME_MAX_LENGTH] = {0};
    fgets(user_input, sizeof(user_input), stdin);

    char character;
    uint8_t number_of_whitespaces = 0;
    uint8_t char_offset = 0;
    char filtered_name[NAME_MAX_LENGTH] = {0};
    uint8_t filtered_index = 0;
    for (int i = 0; i < sizeof(user_input) / sizeof(user_input[0]); i++)
    {
        character = user_input[i];
        // HANDLE UPPERCASE
        if (is_uppercase(character))
        {
            if (filtered_index == 0 || is_whitespace(user_input[i-1]))
            {
                filtered_name[filtered_index] = character;
            }
            else
            {
                filtered_name[filtered_index] = convert_uppercase_to_lowercase(character);
            }
            filtered_index++;
        }
        // HANDLE LOWERCASE
        else if (is_lowercase(character))
        {
            if (filtered_index == 0 || is_whitespace(user_input[i - 1]))
            {
                filtered_name[filtered_index] = convert_lowercase_to_uppercase(character);
            }
            else
            {
                filtered_name[filtered_index] = character;
            }
            filtered_index++;
        }
        // HANDLE WHITESPACE
        else if (is_whitespace(character))
        {
            number_of_whitespaces++;
            if (number_of_whitespaces <= 1)
            {
                filtered_name[filtered_index] = character;
                filtered_index++;
            }
            else
            {
                break;
            }
        }
        else if (character == 0)
        {
            // END FOR LOOP
            break;
        }
    }

    printf("Filtered name: %s", filtered_name);

    return 0;
}
