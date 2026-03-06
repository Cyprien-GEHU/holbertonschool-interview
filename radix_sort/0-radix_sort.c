#include "sort.h"

/**
 * maximum_value - search the maximum value of the array
 * @array: the array
 * @size: the size of array
 * Return: the maximum value of the array
 */
int maximum_value(int *array, size_t size)
{
	int maximum = array[0];
	size_t count;

	for (count = 1; count < size; count++)
	{
		if (array[count] > maximum)
			maximum = array[count];
	}
	return (maximum);
}

/**
 * sort_array_by_exp - sort the array with exp
 * @array: the array
 * @size: the size of array
 * @exp: current digit
 */
void sort_array_by_exp(int *array, size_t size, int exp)
{
	int *memory = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t x;

	if (!memory)
		return;

	for (x = 0; x < size; x++)
		count[(array[x] / exp) % 10]++;

	for (x = 1; x < 10; x++)
		count[x] += count[x - 1];

	for (x = size; x > 0; x--)
	{
		memory[count[(array[x - 1] / exp) % 10] - 1] = array[x - 1];
		count[(array[x - 1] / exp) % 10]--;
	}

	for (x = 0; x < size; x++)
		array[x] = memory[x];

	print_array(array, size);
	free(memory);
}

/**
 * radix_sort - sort a array with the method radix
 * @array: the array
 * @size: the size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = maximum_value(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		sort_array_by_exp(array, size, exp);
}
