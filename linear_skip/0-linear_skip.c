#include "search.h"

/**
 * range - search a range
 * @begin: start of the node
 * @ending: the end of the node
 * @value: the value for the range
 * Return: pointer to the range is locale or NULL
 */

skiplist_t *range(skiplist_t *begin, skiplist_t *ending, int value)
{
	while (begin != NULL && begin->index <= ending->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", begin->index, begin->n);
		if (begin->n == value)
			begin = begin->next;
	}
	return (NULL);
}

/**
 * linear_skip - search for a value in sorted skip list
 * @list:  pointer to the head of the skip list to search in
 * @value: Value we search
 * Return: first node we have the value or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *prev;

	if (list == NULL)
		return (NULL);

	node = list;
	prev = list;

	while (node->express != NULL)
	{
		prev = node;
		node = node->express;
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n >= value)
			break;
	}

	if (node->express == NULL && node->n < value)
	{
		prev = node;
		while (node->next != NULL)
			node = node->next;
	}
	printf("Value checked at index [%lu] = [%lu]\n", prev->index, node->index);
	return (range(prev, node, value));
}
