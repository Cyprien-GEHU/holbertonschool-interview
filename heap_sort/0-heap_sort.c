#include "sort.h"

/**
 * switch_int - switch to interger in the array
 * @array: the array of interger
 * @size: the size of the array
 * @old: first interger selected
 * @new: second interger selected
 */
void switch_int(int *array, size_t size, int *old, int *new)
{
	int tempo;

	if (old != new)
	{
		tempo = *old;
		*old = *new;
		*new = tempo;
		print_array(array, size);
	}
}

/**
 * sift_down - Perfoms the sift down on a the heap
 * @array: the array of interger
 * @size: the size of the array
 * @count: index of the size
 * @current_size: the current size of the heap
 */
void sift_down(int *array, size_t size, size_t count, size_t current_size)
{
	size_t max, Lh, Rh;

	max = count;
	Lh = 2 * count + 1;
	Rh = 2 * count + 2;

	if (Lh < current_size && array[Lh] > array[max])
		max = Lh;

	if (Rh < current_size && array[Rh] > array[max])
		max = Rh;

	if (max != count)
	{
		switch_int(array, size, &array[count], &array[max]);
		sift_down(array, size, max, current_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: the array of intergers
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int count;

	for (count = (size / 2) - 1; count >= 0; count--)
	{
		sift_down(array, size, count, size);
	}

	for (count = size - 1; count > 0; count--)
	{
		switch_int(array, size, &array[0], &array[count]);
		sift_down(array, size, 0, count);
	}
}
