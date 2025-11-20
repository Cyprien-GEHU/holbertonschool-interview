#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * avl_construction - build the avl (recursive)
 * @start: the first index of current subarray
 * @end: the last index of current subarray
 * @array: the array we use for the build
 * @parent: the parent node
 * Return: the pointer of the root node
 */
avl_t *avl_construction(int start, int end, int *array, avl_t *parent)
{
	avl_t *avl;
	int middle;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;
	avl = malloc(sizeof(avl_t));

	if (!avl)
		return (NULL);

	avl->n = array[middle];
	avl->parent = parent;
	avl->left = avl_construction(start, middle - 1, array, avl);
	avl->right = avl_construction(middle + 1, end, array, avl);

	return (avl);
}

/**
 * sorted_array_to_avl - build a avl with a sorted array we send
 * @array: the array we send
 * @size: the size of the array
 * Return: the avl or Null it's fail
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (avl_construction(0, size - 1, array, NULL));
}
