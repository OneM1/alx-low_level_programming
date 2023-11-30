#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int num = 0;

if (!b)
return (0);

for (int i = 0; b[i] != '\0'; i++)
{
num <<= 1;

if (b[i] == '1')
num += 1;
else if (b[i] != '0')
return (0);
}

return (num);
}

