#include "main.h"

/**
 * binaryToUInt - Convert a binary to an unsigned integer.
 * @binaryStr: String containing the binary number.
 *
 * Return: The converted unsigned integer or 0 on error.
 */
unsigned int binaryStringToUInt(const char *binaryStr)
{
    int index;
    unsigned int decimalValue = 0;

    if (!binaryStr)
        return 0;

    for (index = 0; binaryStr[index]; index++)
    {
        if (binaryStr[index] < '0' || binaryStr[index] > '1')
            return 0;
        decimalValue = 2 * decimalValue + (binaryStr[index] - '0');
    }

    return decimalValue;
}

