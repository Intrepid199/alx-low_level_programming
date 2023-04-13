#include "hash_tables.h"

/**
 * key_index - gives you the index of a key
 * @key: pointer to the key
 * @size: size of hash table
 * Return: key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (size == 0)
		return (0);

	return (hash_djb2(key) % size);
}

