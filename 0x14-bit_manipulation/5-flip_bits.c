#include "main.h"

/**
 * flip_bits -  returns the number of bits you would need to flip.
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current_bit;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current_bit = exclusive >> i;
		if (current_bit & 1)
			count++;
	}

	return (count);
}
