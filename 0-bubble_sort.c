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
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each time two elements swapped.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	bool swapped;

	if (array == NULL || size < 2)
	{
		return;
	}

	do {
		swapped = false;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				swapped = true;
			}
		}
		i++;
	} while (swapped);
}
