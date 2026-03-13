#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - take measure of a binary tree
 * @tree: the pointer to the binary tree
 * Return: the height of the binary tree
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
	{
		return (0);
	}

	left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left > right ? left : right);
}

/**
 * bst - check if the tree is a BST
 * @tree: the pointer to the binary tree
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if the binary tree is BST or 0 otherwise
 */
int bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (
		bst(tree->left, min, tree->n) &&
		bst(tree->right, tree->n, max)
	);
}

/**
 * is_balanced - check the avl balance
 * @tree: pointer to the root
 * Return: 1 if is balanced
 */
int is_balanced(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
	{
		return (1);
	}

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left - right > 1 || right - left > 1)
		return (0);

	return (
	is_balanced(tree->left) &&
	is_balanced(tree->right)
	);
}

/**
 * binary_tree_is_avl - check if binary tree is AVL
 * @tree: pointer to root
 * Return: 1 if AVL or otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!bst(tree, INT_MIN, INT_MAX))
		return (0);

	if (!is_balanced(tree))
		return (0);

	return (1);
}
