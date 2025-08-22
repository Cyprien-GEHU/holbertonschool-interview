#include "binary_trees.h"

/**
 * insert_node - insertion new node
 * @node: pointer to the root node
 * @value: the value of the node
 * Return: NULL or the pointer
 */
heap_t *insert_node(heap_t *node, int value)
{
	heap_t *up_node[1024];
	heap_t *current_node = NULL, *new_node = NULL;
	int i = 0, count = 0;

	up_node[count++] = node;

	while (i < count)
	{
		current_node = up_node[i++];
		if (current_node->left == NULL)
		{
			new_node = binary_tree_node(current_node, value);
			current_node->left = new_node;
			return (new_node);
		}
		up_node[count++] = current_node->left;

		if (current_node->right == NULL)
		{
			new_node = binary_tree_node(current_node, value);
			current_node->right = new_node;
			return (new_node);
		}
		up_node[count++] = current_node->right;
	}
	return (NULL);
}

/**
 * bubble_up - restore heap property by swapping node upwards
 * @node: the node
 */
void bubble_up(heap_t *node)
{
	int temp;

	while (node && node->parent && node->parent->n < node->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - insert a value into a Max Binary Heap
 * @root: double pointer to the root node
 * @value: the value of the node insert
 * Return: Null or the node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new_node = insert_node(*root, value);
	bubble_up(new_node);

	while (new_node->parent && new_node->n != value)
		new_node = new_node->parent;

	return (new_node);
}
