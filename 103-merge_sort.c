#include "sort.h"


/**
 * _mergeSubArray - A function that sorts and merges sub-arrays.
 *
 * @src: Data source.
 * @dest: Processed data.
 * @start: First index of the sub array.
 * @mid:  Index of the midpoint of the sub array.
 * @end: Last index (exclusive) of the sub array
 *
 * Return: void
 */

void _mergeSubArray(int *src, int *dest, size_t start, size_t mid, size_t end)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");

	print_array(src + start, mid - start);

	printf("[right]: ");

	print_array(src + mid, end - mid);

	i = start;
	j = mid;

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_array(dest + start, end - start);
}


/**
 * _recursiveMerge - A function that recursively sorts and merges the array.
 *
 * @arr: Array to sort.
 * @temp: Copy of the array to sort.
 * @start: starting index (inclusive)
 * @end: end index (exclusive)
 *
 * Return: void
 */


void _recursiveMerge(int *arr, int *temp, size_t start, size_t end)
{
	size_t mid;

	if (end - start < 2)
		return;

	mid = (start + end) / 2;

	_recursiveMerge(arr, temp, start, mid);
	_recursiveMerge(arr, temp, mid, end);
	_mergeSubArray(arr, temp, start, mid, end);

	for (mid = start; mid < end; mid++)
		arr[mid] = temp[mid];
}


/**
 * merge_sort - A function that sorts an array of integers in
 * ascending order using the Merge sort algorithm.
 *
 * @array: Array to sort.
 * @size: Size of the array
 *
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	size_t i;
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);

	if (temp == NULL)
		return;

	for (i = 0; i < size; i++)
		temp[i] = array[i];

	_recursiveMerge(array, temp, 0, size);
	free(temp);
}
