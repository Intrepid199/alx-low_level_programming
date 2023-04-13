#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: pointer to hashtable
 * @key: key
 * @value: value
 * Return: 1 if success, else 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node, *temp;
	unsigned long int i;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (0);

	i = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[i];

	while (temp != NULL)
	{
		if (strcmp(key, temp->key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			return (1);
		}
		temp = temp->next;
	}

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	node->key = strdup(key);
	node->value =  strdup(value);
	node->next = ht->array[i];
	ht->array[i] = node;

	return (1);
}
