#include "sort.h"


/**
 * merge_array - fusion two array sorted
 * @array: the array
 * @result: memory alloced
 * @L: start index
 * @M: the middle of index
 * @R: end index
 */
void merge_array(int *array, int *result, size_t L, size_t M, size_t R)
{
	size_t left = L, middle = M + 1, i = L;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + L, M - left + 1);
	printf("[right]: ");
	print_array(array + M + 1, R - M);

	while (left <= M && middle <= R)
	{
		if (array[left] <= array[middle])
			result[i++] = array[left++];
		else
			result[i++] = array[middle++];
	}
	while (left <= M)
		result[i++] = array[left++];
	while (middle <= R)
		result[i++] = array[middle++];

	for (left = L; left <= R; left++)
		array[left] = result[left];

	printf("[Done]: ");
	print_array(array + L, R - L + 1);
}


/**
 * sort_recursive - sort a into 2 array
 * @array: the array
 * @result: memory alloced
 * @L: start index
 * @R: end index
 */
void sort_recursive(int *array, int *result, size_t L, size_t R)
{
	size_t M;

	if (L >= R)
		return;

	M = L + (R - L) / 2;
	sort_recursive(array, result, L, M);
	sort_recursive(array, result, M + 1, R);
	merge_array(array, result, L, M, R);
}


/**
 * merge_sort - sort a array
 * @array: the array
 * @size: the size of array
 */
void merge_sort(int *array, size_t size)
{
	int *result;

	if (!array || size < 2)
		return;

	result = malloc(sizeof(int) * size);
	if (!result)
		return;

	sort_recursive(array, result, 0, size - 1);
	free(result);
}
