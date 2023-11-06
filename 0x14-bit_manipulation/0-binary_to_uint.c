#include "my_header.h"

/**
 * binary_to_unsigned - converts a binary input to an unsigned integer
 * @binary_input: string containing the binary number
 *
 * Returns: the converted integer or 0 on invalid input
 */
unsigned int parse_binary_to_unsigned(const char *binary_input)
{
    if (!binary_input)
        return 0;

    unsigned int result = 0;
    char current_char;

    while ((current_char = *binary_input++))
    {
        if (current_char != '0' && current_char != '1')
            return 0;

        result = (result << 1) | (current_char - '0');
    }

    return result;
}

