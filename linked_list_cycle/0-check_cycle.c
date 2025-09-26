#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: the linked list
 * Return: 1 is cycle, 0 is not cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *fast, *slow;

	if (list == NULL)
		return (0);

	fast = slow = list;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (1);
	}

	return (0);
}
