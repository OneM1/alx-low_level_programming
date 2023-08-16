#include "main.h"
#include <stdio.h>
/**
 * abs - function that computes the absolute value of an integer
 * @i:  is the int that will use for the argument of the function
 * Return: 0
 */
int _abs(int i)
{
	if (i > 0 || i == 0)
	{
	return (i);
	}
	else
	return (i * -1);
}

