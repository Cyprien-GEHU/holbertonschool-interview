#include "lists.h"

/**
 * copy_reverse_list - Crée une copie inversée d'une liste chaînée
 * @head: pointeur vers le début de la liste à copier
 * Return: pointeur vers la nouvelle liste inversée, ou NULL en cas d'échec
 */
listint_t *copy_reverse_list(listint_t *head)
{
	listint_t *new_head = NULL, *new_node = NULL;

	while (head)
	{
		new_node = malloc(sizeof(listint_t));
		if (!new_node)
		{
			while (new_head)
			{
				listint_t *tmp = new_head->next;

				free(new_head);
				new_head = tmp;
			}
			return (NULL);
		}
		new_node->n = head->n;
		new_node->next = new_head;
		new_head = new_node;
		head = head->next;
	}
	return (new_head);
}

/**
 * is_palindrome - check the linked list is palindrome style
 * @head: the linked list
 * Return: 1 if palindrome, or 0 if is not the case
 */
int is_palindrome(listint_t **head)
{
	listint_t *rev, *cur, *to_free;
	int result = 1;

	if (!head || !*head || !(*head)->next)
		return (1);

	rev = copy_reverse_list(*head);
	cur = *head;
	to_free = rev; /* Garder le début de la liste inversée */

	while (cur && rev)
	{
		if (cur->n != rev->n)
		{
			result = 0;
			break;
		}
		cur = cur->next;
		rev = rev->next;
	}

	/* Libérer la liste inversée */
	while (to_free)
	{
		listint_t *tmp = to_free->next;
		free(to_free);
		to_free = tmp;
	}

	return (result);
}
