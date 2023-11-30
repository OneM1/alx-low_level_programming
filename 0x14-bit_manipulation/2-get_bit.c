#include "main.h"

/**
 * get_bit -function  gets the value of a bit at a given index
 * @n: the number to check
 * @index: the index, starting from 0, of the bit to get
 *
 * Return: the value of the bit at index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
if (index > (sizeof(n) * 8))
return (-1);

return ((n >> index) & 1);
}

