#include "search_algos.h"


/**
 * print_array - print an array
 * @array: the current array
 * @size: size of current array
 */
void print_array(int *array, size_t size)
{
	size_t count;

	printf("Searching in array: ");
	for (count = 0; count < size; count++)
	{
		if (count > 0)
			printf(", ");
		printf("%d", array[count]);
	}
	printf("\n");

}


/**
 * advanced_binary_recur - search for first occurence with recursively
 * @array: first element to array
 * @left: Starting index
 * @right: Ending index
 * @value: the value serach for
 *
 * Return: index where the values are or -1
 */
int advanced_binary_recur(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array + left, right - left + 1);

	mid = left + (right - left) / 2;

	if (array[mid] == value &&
	   (mid == left || array[mid - 1] != value))
		return (mid);

	if (array[mid] >= value)
		return (advanced_binary_recur(array, left, mid - 1, value));

	return (advanced_binary_recur(array, mid + 1, right, value));
}


/**
 * advanced_binary - Search a value an sorted array of interger
 * @array: the array
 * @size: the size of array
 * @value: value we search
 *
 * Return: index where the values are or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recur(array, 0, size - 1, value));
}
