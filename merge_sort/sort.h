#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge_array(int *array, int *result, size_t L, size_t M, size_t R);
void sort_recursive(int *array, int *result, size_t L, size_t R);

#endif
