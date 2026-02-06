#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
static void merge_sort_recursive(int *array, int *aux, size_t left,
		size_t right);
static void merge_sort_recursive(int *array, int *aux, size_t left,
		size_t right)

#endif
