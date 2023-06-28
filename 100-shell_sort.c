#include <stdio.h>
#include "sort.h"
/**
 * shell_sort - shell sort algorithm
 * @array: array
 * @size: length of the array to sort
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		size_t i;

		for (i = gap; i < size; i++)
		{
			int temp = array[i];
			size_t j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap /= 2;
	}

}
