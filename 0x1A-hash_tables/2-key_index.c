#include "hash_tables.h"

/**
 * key_index - Gives the index of a key in the hash table array
 * @key: The key
 * @size: The size of the array of the hash table
 *
 * Return: The index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
/* Get the hash value using djb2 algorithm */
unsigned long int hash_value = hash_djb2(key);
/* Compute the index by taking modulus of hash value with the size of array */
unsigned long int index = hash_value % size;
return (index);
}
