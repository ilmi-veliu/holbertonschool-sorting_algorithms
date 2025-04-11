#include "sort.h"

/**
 * lomuto_partition - lomuto partition for quick sort
 * @array: array to partition
 * @left_index: left index of the array
 * @right_index: right index of the array
 * @size: size of array
 * Return: index of pivot after partition
 */

int lomuto_partition(int *array, int left_index, int right_index, size_t size)
{
	int pivot = array[right_index];
	int i = left_index, j = left_index, temp = 0;

	for (; j < right_index; j++)
	{
		if (array[j] <= pivot)
		{
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i < right_index)
	{
		temp = array[i];
		array[i] = array[right_index];
		array[right_index] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * recusive_QS - recusive quick sort to keep size of array
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 * @left_index: start of left subarray
 * @right_index: start of right subarray
 */

void recusive_QS(int *array, size_t size, int left_index, int right_index)
{
	int pivot_index = 0;

	if (left_index < right_index)
	{
		pivot_index = lomuto_partition(array, left_index, right_index, size);
		recusive_QS(array, size, left_index, pivot_index - 1);
		recusive_QS(array, size, pivot_index + 1, right_index);
	}
}


/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	recusive_QS(array, size, 0, size - 1);
}
