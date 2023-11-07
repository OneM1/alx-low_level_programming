#include "main.h"

/**
 * convertBinaryToInt - Function to convert a binary  to an unsigned int.
 * @binaryStr: Pointer to a string containing a binary number.
 *
 * Return: The unsigned int value of the binary number, or 0 if there's an error.
 */
unsigned int convertBinaryToUInt(const char *binaryStr)
{
    int index;
    unsigned int result;

    result = 0;

    if (!binaryStr)
        return 0;

    // Check if the string contains valid binary characters
    for (index = 0; binaryStr[index] != '\0'; index++)
    {
        if (binaryStr[index] != '0' && binaryStr[index] != '1')
            return 0;
    }

    // Convert the binary string to an unsigned int
    for (index = 0; binaryStr[index] != '\0'; index++)
    {
        result <<= 1;
        if (binaryStr[index] == '1')
            result += 1;
    }

    return result;
}

