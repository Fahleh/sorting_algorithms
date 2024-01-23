#include "sort.h"

/**
 * _swap - A function that swaps two nodes in list
 *
 * @head: Pointer to the head of the list.
 * @node: Node to swap
 *
 * Return: void
 */

void _swap(listint_t **head, listint_t *node)
{
	if (node->next)
	{
		node->next->prev = node->prev;
	}

	if (node->prev)
	{
		node->prev->next = node->next;
	}
	else
	{
		*head = node->next;
	}

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head of the list.
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				_swap(list, temp);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				temp = temp->next;
			}
		}
		if (swapped == 0)
			break;

		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				_swap(list, temp->prev);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				temp = temp->prev;
			}
		}
	}
}
