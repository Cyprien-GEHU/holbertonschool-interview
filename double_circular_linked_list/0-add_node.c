#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * add_node_end - add a noeud in this end of the double linked list
 * @list: the list
 * @str: the value of node
 * Return: the node
 */
List *add_node_end(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->prev = new;
		new->next = new;
		*list = new;
		return (new);
	}

	List *last = (*list)->prev;

	new->prev = last;
	new->next = *list;
	last->next = new;
	(*list)->prev = new;

	return (new);
}

/**
 * add_node_begin - add a node in the begin of the double linked list
 * @list: the list
 * @str: the value of the node
 * Return: the node
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->prev = new;
		new->next = new;
		*list = new;
		return (new);
	}

	List *last = (*list)->prev;

	new->prev = last;
	new->next = *list;
	last->next = new;
	(*list)->prev = new;

	*list = new;

	return (new);
}
