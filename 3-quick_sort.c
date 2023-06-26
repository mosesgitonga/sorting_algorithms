#include "sort.h"

	void swap(int *a, int *b)
	{
		int tmp;

		tmp = *a;
		*a = *b;
		*b = tmp;
	}

	int partition(int *array, int low, int high)
	{
		int pivot, i, j;

		pivot = array[high];
		i = low - 1;

		for (j = low; j <= high - 1; j++)
		{
			if (array[j] < pivot)
			{
				i++;
				swap(&array[i], &array[j]);
				print_array(array, high + 1);
			}

		}
		swap(&array[i + 1], &array[high]);

		return i + 1;
	}

	void quick_sort_recursive(int *array, int low, int high)
	{
		if (low < high)
		{
			int pi;

			pi = partition(array, low, high);

			quick_sort_recursive(array, low, pi - 1);
			quick_sort_recursive(array, pi + 1, high);

		}
	}
	void quick_sort(int *array, size_t size)
	{
		if (array == NULL || size <= 1)
		{
			return;
		}
		quick_sort_recursive(array, 0, size - 1);
	}

