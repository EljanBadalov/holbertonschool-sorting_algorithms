#include "sort.h"

/**
 * swap_nodes - Swap a node with the previous node in a doubly linked list
 * @list: Pointer to pointer to the head of the list
 * @node: Pointer to the node to move left (swap with prev)
 */
static void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev = node->prev;
	listint_t *next = node->next;

	if (!prev)
		return;

	/* link prev->prev to node */
	if (prev->prev)
		prev->prev->next = node;
	else
		*list = node;

	node->prev = prev->prev;

	/* link node to prev */
	node->next = prev;
	prev->prev = node;

	/* link prev to next */
	prev->next = next;
	if (next)
		next->prev = prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Pointer to pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			swap_nodes(list, current);
			print_list(*list);
		}

		current = next;
	}
}
