#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: The number to search for the bit.
 * @index: The index of the bit to retrieve.
 *
 * Return: The value of the bit at the specified index (0 or 1), or -1 if index is out of range.
 */
int get_bit(unsigned long int n, unsigned int index)
{
    int bit_value;

    if (index > 63)  
        return (-1);

    bit_value = (n >> index) & 1;

    return (bit_value);
}
