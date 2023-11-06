#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @binary_str: string containing the binary number
 *
 * Return: the converted number as an unsigned int
 */
unsigned int binary_to_uint(const char *binary_str)
{
    int index;
    unsigned int decimal_value = 0;

    if (!binary_str)
        return (0);

    for (index = 0; binary_str[index]; index++)
    {
        if (binary_str[index] < '0' || binary_str[index] > '1')
            return (0);
        decimal_value = 2 * decimal_value + (binary_str[index] - '0');
    }

    return (decimal_value);
}

