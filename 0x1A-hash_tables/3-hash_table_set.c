#include "hash_tables.h"
#include <string.h>

hash_node_t *create_new_node(const char *key, const char *value)
{
hash_node_t *new_node = malloc(sizeof(hash_node_t));
if (new_node == NULL)
	return NULL;

new_node->key = strdup(key);
if (new_node->key == NULL)
{
free(new_node);
return NULL;
}

new_node->value = strdup(value);
if (new_node->value == NULL)
{
free(new_node->key);
free(new_node);
return NULL;
}

new_node->next = NULL;

return new_node;
}

int update_existing_node(hash_node_t *node, const char *value)
{
char *new_value = strdup(value);
if (new_value == NULL)
return 0;

free(node->value);
node->value = new_value;

return 1;
}

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
hash_node_t *temp;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return 0;

index = key_index((unsigned char *)key, ht->size);
temp = ht->array[index];

while (temp != NULL)
{
if (strcmp(temp->key, key) == 0)
return update_existing_node(temp, value);
temp = temp->next;
}

temp = create_new_node(key, value);
if (temp == NULL)
return 0;

temp->next = ht->array[index];
ht->array[index] = temp;

return 1;
}
