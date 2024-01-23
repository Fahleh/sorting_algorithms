#include "sort.h"


/**
 * _siftDown - A function that implements the Sift-down sort algorithm.
 *
 * @array: The heap to sort.
 * @root: Root of the heap
 * @end: Index of the last element in the heap.
 * @size: Size of the array
 *
 * Return: void
 */

void _siftDown(int *array, size_t root, size_t end, size_t size)
{
	size_t left, right, swap;
	int temp;

	while ((left = (2 * root) + 1) <= end)
	{
		swap = root;
		right = left + 1;
		if (array[swap] < array[left])
			swap = left;

		if (right <= end && array[swap] < array[right])
			swap = right;

		if (swap == root)
			return;
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}


/**
 * heap_sort - A function that sorts an array of ints in
 * ascending order using the Heap sort algorithm.
 *
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	size_t end, parent;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (parent = ((size - 1) - 1) / 2; 1; parent--)
	{
		_siftDown(array, parent, size - 1, size);
		if (parent == 0)
			break;
	}

	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		_siftDown(array, 0, end, size);
	}
}
