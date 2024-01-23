#include "sort.h"



/**
 * _recursiveMerge - A function that recursively merges two arrays.
 *
 * @array: Array to sort
 * @dir: Sort direction.
 * @size: Size of the array
 *
 * Return: void
 */

void _recursiveMerge(int *array, char dir, size_t size)
{
	size_t i, dist;
	int temp;

	if (size < 2)
		return;

	dist = size / 2;
	for (i = 0; i < dist; i++)
	{
		if ((array[i] > array[i + dist]) == dir)
		{
			temp = array[i];
			array[i] = array[i + dist];
			array[i + dist] = temp;
		}
	}

	_recursiveMerge(array, dir, dist);
	_recursiveMerge((array + dist), dir, dist);
}

/**
 * _recursiveSort - A recursive function that implements
 * the Bitonic sort algorithm
 *
 * @array: Array to sort
 * @dir: Sort direction.
 * @size: Size of the sub-array
 * @total_size: Size of original array
 *
 * Return: void
 */

void _recursiveSort(int *array, char dir, size_t size, size_t total_size)
{
	if (size < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n",
			size, total_size, (dir == 1) ? "UP" : "DOWN");

	print_array(array, size);

	_recursiveSort(array, 1, size / 2, total_size);
	_recursiveSort(array + (size / 2), 0,  size / 2, total_size);

	_recursiveMerge(array, dir, size);
	printf("Result [%lu/%lu] (%s):\n", size, total_size,
			(dir == 1) ? "UP" : "DOWN");

	print_array(array, size);

}

/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm.
 *
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Void
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_recursiveSort(array, 1, size, size);
}
