#include "sort.h"

/**
 * bubble_sort - sort an array of integers in ascending order
 *
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag, tmp;

	if (size < 2)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		flag = 0;
		for (j = 0; j < (size - 1) - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				flag = 1;

				/*print the array after each swap is done*/
				print_array(array, size);
			}
		}
		if (flag == 0)
			return;
	}
}
