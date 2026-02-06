#include "sort.h"

static void merge_sort_recursive(int *array, int *aux, size_t left,
		size_t right);

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge Sort algorithm (top-down)
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *aux;

	if (!array || size < 2)
		return;

	aux = malloc(sizeof(int) * size);
	if (!aux)
		return;

	merge_sort_recursive(array, aux, 0, size);

	free(aux);
}

/**
 * merge_sort_recursive - Recursively sorts subarrays using merge sort
 * @array: The array to sort
 * @aux: Auxiliary array for merging
 * @left: Left index of the subarray
 * @right: Right index (exclusive) of the subarray
 */
static void merge_sort_recursive(int *array, int *aux, size_t left,
		size_t right)
{
	size_t n = right - left;
	size_t mid, i, j, k;

	if (n < 2)
		return;

	mid = left + n / 2;

	merge_sort_recursive(array, aux, left, mid);
	merge_sort_recursive(array, aux, mid, right);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;
	k = left;

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			aux[k++] = array[i++];
		else
			aux[k++] = array[j++];
	}

	while (i < mid)
		aux[k++] = array[i++];

	while (j < right)
		aux[k++] = array[j++];

	for (k = left; k < right; k++)
		array[k] = aux[k];

	printf("[Done]: ");
	print_array(array + left, n);
}
