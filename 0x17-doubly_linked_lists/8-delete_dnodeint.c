#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes the node at index index of a linked list
 * @head: Pointer to first node
 * @index: Index
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head;
	dlistint_t *aux;
	unsigned int count = 0;

	if (*head == NULL)
		return (-1);
	if (tmp == NULL)
		return (-1);
	if (index == 0)
	{
		if (tmp->next != NULL)
		{
			*head = (*head)->next;
			(*head)->prev = NULL;
		}
		else
			*head = NULL;
		free(tmp);
		return (1);
	}
	for (count = 0; count < index && tmp != NULL; count++)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (-1);
	}
	if (tmp->next == NULL)
	{
		tmp->prev->next = NULL;
		free(tmp);
		return (1);
	}
	aux = tmp;
	tmp->next->prev = aux->prev;
	tmp->prev->next = aux->next;
	free(tmp);
	return (1);
}

