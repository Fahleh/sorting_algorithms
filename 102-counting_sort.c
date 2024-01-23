#include "sort.h"

/**
 * _findMax - A function that finds the maximum value in an array of integers.
 *
 * @array: Array to search.
 * @size: Size of the array.
 *
 * Return: The largest integer.
 */

int _findMax(int *array, int size)
{
	int i, max;

	for (i = 1, max = array[0]; i < size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}

	return (max);
}

/**
 * counting_sort - A function thatt sorts an array of integers in
 * ascending order using the counting sort algorithm.
 *
 * @array: Array to sort.
 * @size: Size of the array.
 *
 * Return: Void.
 */

void counting_sort(int *array, size_t size)
{
	int i, *count, *temp, max, size_copy = (int)size;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	max = _findMax(array, size_copy);

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(temp);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < size_copy; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < size_copy; i++)
	{
		temp[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < size_copy; i++)
		array[i] = temp[i];

	free(temp);
	free(count);
}
