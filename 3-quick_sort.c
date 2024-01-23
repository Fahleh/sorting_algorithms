#include "sort.h"


/**
 * _partition - A function that finds the partition for the
 * quicksort using the Lomuto scheme.
 *
 * @array: Array to be sorted
 * @start: Start of the partition.
 * @end: End of the partition.
 * @size: Size of array
 *
 * Return: Index of the partition
 */

int _partition(int *array, int start, int end, int size)
{
	int i, j, temp, pivot;

	pivot = array[end];
	i = start - 1;
	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

				print_array(array, size);
			}
		}
	}

	if (array[end] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = temp;

		print_array(array, size);
	}

	return (i + 1);
}


/**
 * _sort - A function that sorts a partition of an integer array.
 *
 * @array: Arrray to be sorted
 * @start: Start of the partition.
 * @end: End of the partition.
 * @size: Size of the array.
 *
 * Return: Void.
 */

void _sort(int *array, int start, int end, int size)
{
	int pivot;

	if (start < end)
	{
		pivot = _partition(array, start, end, size);

		_sort(array, start, pivot - 1, size);
		_sort(array, pivot + 1, end, size);
	}
}


/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	_sort(array, 0, size - 1, size);
}
