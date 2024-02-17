#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table to look into
 * @key: The key to look for
 *
 * Return: The value associated with key,or NULL if the key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
unsigned long int index;
hash_node_t *node;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

/* Get the index for the key */
index = key_index((const unsigned char *)key, ht->size);

/* Traverse the linked list at the computed index */
node = ht->array[index];
while (node != NULL)
{
/* Compare the keys */
if (strcmp(node->key, key) == 0)
return (node->value); /* Key found, return the associated value */
node = node->next;
}

return (NULL); /* Key not found */
}
