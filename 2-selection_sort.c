#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
*/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using selection sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each time an element swapped.
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int *low_num;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		low_num = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *low_num)
			{
				low_num = array + j;
			}
		}

		if ((array + i) != low_num)
		{
			swap_ints(array + i, low_num);
			print_array(array, size);
		}
	}
}
