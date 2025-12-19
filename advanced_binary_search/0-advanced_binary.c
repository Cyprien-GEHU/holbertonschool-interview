#include "search_algos.h"

/**
 * print_array - Prints an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Recursively searches for first occurrence
 * @array: Pointer to the first element of the array to search
 * @left: Starting index of the current subarray
 * @right: Ending index of the current subarray
 * @value: Value to search for
 *
 * Return: Index of first occurrence of value, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	print_array(array + left, right - left + 1);

	/* Base case: single element */
	if (left == right)
	{
		if (array[left] == value)
			return (left);
		return (-1);
	}

	mid = left + (right - left) / 2;

	/* If mid value >= target, search left half including mid */
	if (array[mid] >= value)
		return (advanced_binary_recursive(array, left, mid, value));

	/* If mid value < target, search right half excluding mid */
	return (advanced_binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}