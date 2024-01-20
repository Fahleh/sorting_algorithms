#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 *
 * @list: A double pointer to the head of the list.
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *next;

	if (list == NULL || *list == NULL)
		return;

	temp = (*list)->next;
	while (temp != NULL)
	{
		next = temp->next;
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		temp = next;
	}
}
