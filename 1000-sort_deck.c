#include "deck.h"

int _getValue(const char *name);
void _swap(deck_node_t **head, deck_node_t *node);

/**
 * sort_deck - A function that sorts a deck of cards.
 *
 * @deck: Deck to sort
 *
 * Return: void
 */

void sort_deck(deck_node_t **deck)
{
	char card_1, card_2, flag = 1;
	deck_node_t *active;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	active = *deck;
	while (flag != 0)
	{
		flag = 0;

		while (active->next != NULL)
		{
			card_1 = _getValue(active->card->value) + 13 * active->card->kind;
			card_2 = _getValue(active->next->card->value) + 13 * active->next->card->kind;
			
			if (card_1 > card_2)
			{
				_swap(deck, active);
				flag = 1;
			}
			else
			{
				active = active->next;
			}
		}

		if (flag == 0)
			break;
		
		flag = 0;
		while (active->prev != NULL)
		{
			card_1 = _getValue(active->card->value) + 13 * active->card->kind;
			card_2 = _getValue(active->prev->card->value) + 13 * active->prev->card->kind;
			
			if (card_1 < card_2)
			{
				_swap(deck, active->prev);
				flag = 1;
			}
			else
			{
				active = active->prev;
			}
		}
	}
}


/**
 * _getValue - A function that gets the integer value of a card.
 *
 * @name: Name of the card
 *
 * Return: Integer value of the card.
 */

int _getValue(const char *name)
{
	int i;
	char *cards[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(name, cards[i]) == 0)
		{
			return (i);
		}
	}
	exit(1);
}

/**
 * _swap - A function that swaps the nodes of a list.
 *
 * @head: Pointer to the head of the list.
 * @node: Node to swap
 *
 * Return: Void.
 */

void _swap(deck_node_t **head, deck_node_t *node)
{
	node->next->prev = node->prev;

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
	{
		node->next->prev = node;
	}
}
