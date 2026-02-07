#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
static void swap_ints(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index (pivot is array[high])
 * @size: Size of the array
 *
 * Return: The final position of the pivot
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				if (array[i] != array[j])
				{
					swap_ints(&array[i], &array[j]);
					print_array(array, size);
				}
				else
				{
					swap_ints(&array[i], &array[j]);
				}
			}
		}
	}

	if (i + 1 != high)
	{
		if (array[i + 1] != array[high])
		{
			swap_ints(&array[i + 1], &array[high]);
			print_array(array, size);
		}
		else
		{
			swap_ints(&array[i + 1], &array[high]);
		}
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts an array using quick sort
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
static void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * (Lomuto partition scheme)
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}
