#include "sort.h"

/**
 * _getPortion - A function that gets a portion of an array.
 *
 * @array: Array to sort.
 * @min: Lowest index of portion to sort.
 * @max: Highest index of portion to sort.
 * @size: Size of the array
 *
 * Return: Index of sub-array.
 */

size_t _getPortion(int *array, ssize_t min, ssize_t max, size_t size)
{
	int temp, ref;

	ref = array[max];

	while (min <= max)
	{
		while (array[min] < ref)
			min++;
		while (array[max] > ref)
			max--;
		if (min <= max)
		{
			if (min != max)
			{
				temp = array[min];
				array[min] = array[max];
				array[max] = temp;
				print_array(array, size);
			}
			min++;
			max--;
		}
	}

	return (max);
}


/**
 * _sort - A function that sorts a portion of an array of integers.
 *
 * @array: Array to sort
 * @min: Lowest index of portion to sort
 * @max: Highest index of portion to sort
 * @size: Size of the array
 *
 * Return: void
 */

void _sort(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t pivot;

	if (min < max)
	{
		pivot = _getPortion(array, min, max, size);

		_sort(array, min, pivot, size);
		_sort(array, pivot + 1, max, size);

	}
}

/**
 * quick_sort_hoare - A function that sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 *
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_sort(array, 0, size - 1, size);
}
