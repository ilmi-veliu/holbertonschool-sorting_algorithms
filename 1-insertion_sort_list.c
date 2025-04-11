#include "sort.h"

/**
 * listint_len -prints the number of elements in a dlistint_t list
 * @h: list
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h)
{
	int node_number = 0;

	if (h == NULL)
	return (node_number);

	while (h != NULL)
	{
		node_number++;
		h = h->next;
	}
	return (node_number);
}

/**
 * swap - swap two nodes
 * @prevNode: 1st node to become 2nd
 * @currentNode: 2nd node to become 1st
 * Return: pointer to currentNode
 */

listint_t *swap(listint_t *prevNode, listint_t *currentNode)
{
	prevNode->next = currentNode->next;

	if (currentNode->next != NULL)
	currentNode->next->prev = prevNode;

	currentNode->next = prevNode;

	currentNode->prev = prevNode->prev;

	prevNode->prev = currentNode;

	if (currentNode->prev != NULL)
	currentNode->prev->next = currentNode;

	if (prevNode->next != NULL)
	prevNode->next->prev = prevNode;

	return (currentNode);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list of integers
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node = NULL, *next_node = NULL;

	if (list == NULL || listint_len(*list) <= 1)
	return;

	curr_node = (*list)->next;

	while (curr_node != NULL)
	{
		next_node = curr_node->next;

		while (curr_node->prev != NULL && (curr_node->n < curr_node->prev->n))
		{
			curr_node = swap(curr_node->prev, curr_node);

			if (curr_node->prev == NULL)
			*list = curr_node;

			print_list(*list);
		}
		curr_node = next_node;
	}
}
