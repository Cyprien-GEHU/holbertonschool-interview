#include "binary_trees.h"

/**
 * tree_size - count the numbe of nodes on a binary tree
 * @tree: the root node
 *
 * Return: number nodes or 0 if NULL
 */
size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_nodes_with_index - get the node with a index
 * @root: the node
 * @size: number total node in tree
 *
 * Return: the index of the node
 */
heap_t *get_nodes_with_index(heap_t *root, size_t size)
{
	size_t bin;
	heap_t *node = root;

	if (!node)
		return (NULL);

	for (bin = 1; bin <= size; bin <<= 1)
		;

	bin >>= 2;

	while (bin > 0 && node)
	{
		if (size & bin)
			node = node->right;
		else
			node = node->left;
		bin >>= 1;
	}
	return (node);
}

/**
 * heap_down - heapify
 * @node: the node
 */
void heap_down(heap_t *node)
{
	heap_t *larg;
	int tempo;

	if (!node)
		return;

	while (node->left || node->right)
	{
		larg = node;

		if (node->left && node->left->n > larg->n)
			larg = node->left;

		if (node->right && node->right->n > larg->n)
			larg = node->right;

		if (larg == node)
			return;

		tempo = node->n;
		node->n = larg->n;
		larg->n = tempo;

		node = larg;
	}
}


/**
 * heap_extract - extract the root of the max binary heap
 * @root : double pointer
 * Return: Value stored on the root or 0 if is a failure
 */
int heap_extract(heap_t **root)
{
	int value;
	size_t size;
	heap_t *node;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	size = tree_size(*root);
	node = get_nodes_with_index(*root, size);

	(*root)->n = node->n;
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	free(node);

	heap_down(*root);

	return (value);
}
