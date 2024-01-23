#include "sort.h"


/**
 * _countingSort - A function that sorts the digits of an array of integers in
 * ascending order using the counting sort algorithm.
 *
 * @array: Array of integers.
 * @size: Size of the array.
 * @digit: Digit to base sort on.
 * @buffer: A buffer to store the sorted array.
 *
 *
 * Return: Void.
 */

void _countingSort(int *array, size_t size, int digit, int *buffer)
{
	size_t i;
	int count[10] = {0};

	for (i = 0; i < 10 ; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / digit) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - A function that sorts an array of integers in
 * ascending order using the radix sort algorithm.
 *
 * @array: Array to sort.
 * @size: Size of the array.
 *
 * Return: Void.
 */

void radix_sort(int *array, size_t size)
{
	int max, digit, *buffer;
	size_t i;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (digit = 1; max / digit > 0; digit *= 10)
	{
		_countingSort(array, size, digit, buffer);
		print_array(array, size);
	}

	free(buffer);
}
