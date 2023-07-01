#include <stdio.h>
#include "sort.h"

void quick_sorti(int *array, int low, int high);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, int low, int high);
void swap(int *a, int *b);

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 *                    Quick sort algorithm (Hoare partition scheme).
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sorti(array, 0, size - 1);
}

/**
 * quick_sorti - Recursively sorts an array of integers in ascending order using
 *               the Quick sort algorithm (Hoare partition scheme).
 * @array: The array to be sorted.
 * @low: The lowest index of the array to sort.
 * @high: The highest index of the array to sort.
 */
void quick_sorti(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high);
        print_array(array, high);
        quick_sorti(array, low, pivot);
        print_array(array, high);
        quick_sorti(array, pivot + 1, high);
    }
}

/**
 * hoare_partition - Partitions an array using the Hoare partition scheme.
 * @array: The array to be partitioned.
 * @low: The lowest index of the array to partition.
 * @high: The highest index of the array to partition.
 *
 * Return: The index of the partition.
 */
int hoare_partition(int *array, int low, int high)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
    }
}

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
