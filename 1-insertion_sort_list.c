#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: A pointer the first node to swap.
 * @node2: The second node to swap.
*/
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (node2->next != NULL)
	{
		node2->next->prev = *node1;
	}

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
	{
		(*node1)->prev->next = node2;
	}
	else
	{
		*head = node2;
	}
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order.
 * @list: A pointer to the head of doubly-linked list of integers.
 *
 * Description: Prints the list after each time two elements swapped.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *key, *ins, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (key = (*list)->next; key != NULL; key = tmp)
	{
		tmp = key->next;
		ins = key->prev;

		while (ins != NULL && key->n < ins->n)
		{
			swap_nodes(list, &ins, key);
			print_list((const listint_t *)*list);
		}
	}
}
