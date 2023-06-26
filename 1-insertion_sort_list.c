#include "sort.h"
/**
 * insertion_sort_list - insertion algorithm for a linked list
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *next;

	if (list ==  NULL || *list == NULL || (*list) == NULL)
	{
		return;
	}

	while (current != NULL)
	{
		next = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = current->prev;
			}
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (current->prev == NULL)
			{
				*list = current;
			}
			else
			{
				current->prev->next = current;
			}

			print_list(*list);
		}
		current = next;
	}
}
