#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *binary_str)
{
	unsigned int decimal_val;
	int str_length, binary_base;

	if (!binary_str)
		return (0);

	decimal_val = 0;

	for (str_length = 0; binary_str[str_length] != '\0'; str_length++)
		;

	for (str_length--, binary_base = 1; str_length >= 0; str_length--, binary_base *= 2)
	{
		if (binary_str[str_length] != '0' && binary_str[str_length] != '1')
		{
			return (0);
		}

		if (binary_str[str_length] & 1)
		{
			decimal_val += binary_base;
		}
	}

	return (decimal_val);
}

