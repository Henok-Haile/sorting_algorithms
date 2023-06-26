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
 * partition - orders the smallest part to the left and the highest part
 * to the right to the reference the last element as a pivot value.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @low: Starting index of the left part to be ordered.
 * @high: Ending index of the right part to be ordered.
 *
 * Return: The final partition of index.
 */
int partition(int *array, size_t size, int low, int high)
{
	int *pivot_value, i, j;

	pivot_value = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot_value)
		{
			if (i < j)
			{
				swap_ints(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot_value)
	{
		swap_ints(array + i, pivot_value);
		print_array(array, size);
	}

	return (i);
}
/**
 * quicksort_recursion - Sorting the array using quicksort algorithm
 * through recursion.
 * @array: An array of integers to be sorted.
 * @size: Size of the array.
 * @low: Starting index of the array partition to be ordered.
 * @high: Ending index of the array partition to be ordered.
 */
void quicksort_recursion(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, size, low, high);
		quicksort_recursion(array, size, low, pivot_index - 1);
		quicksort_recursion(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using quick sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each time an element swapped.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quicksort_recursion(array, size, 0, size - 1);
}
