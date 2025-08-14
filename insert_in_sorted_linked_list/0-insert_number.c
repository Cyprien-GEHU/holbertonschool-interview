#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * insert_node - function to insert the integer on a linked list
 * @head: the pointer to first node of linked list
 * @number: the interger to include on a sorted linked list
 * 
 * Return: Null if failed or the adress of the new node
*/

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *orignal_list;
    listint_t *new_list = malloc(sizeof(listint_t));

    if (new_list == NULL) 
        return (NULL);

    new_list->n = number;
    new_list->next = NULL;

    if (*head == NULL)
    {
        *head = new_list;
        return (new_list);
    }

    if ((*head)->n > number)
    {
        new_list->next = *head;
        *head = new_list;
        return (new_list);
    }

    orignal_list = *head;
    while (orignal_list->next != NULL && orignal_list->next->n <number)
    {
        orignal_list = orignal_list->next;
    }

    new_list->next = orignal_list->next;
    orignal_list->next = new_list;

    return (new_list);
    
}