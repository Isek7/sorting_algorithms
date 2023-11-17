#include "sort.h"

/**
* maxValue - Function returns the maximum value in an array
* @array: array to find max value of
* @size: Size of array
* Return: maximum value
*/

int maxValue(int *array, size_t size)
{
	int i, max = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
* radix_sort - Sorts an array using radix sort algo
* @array: Array to sort
* @size: size of array
*/

void radix_sort(int *array, size_t size)
{
	int m, pos, *out, *ca;

	if (array == NULL || size < 2)
		return;
	m = maxValue(array, size);
	out = malloc(sizeof(int) * (int)size);
	ca = malloc(sizeof(int) * (10));
	if (ca == NULL || out == NULL)
		return;
	for (pos = 1; m / pos > 0; pos *= 10)
		numbering_sort_ar(array, size, pos, out, ca), print_array(array, size);
	free(out);
	free(ca);
}

/**
* numbering_sort_ar - sorts array using numbering algorithm
* @array: Array to sort
* @size: Size of array
* @pos: Digit position value
* @out: Temp output array
* @ca: Count array
*/

void numbering_sort_ar(int *array, size_t size, int pos, int *out, int *ca)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < 10; i++)
		ca[i] = 0;
	for (i = 0; i < (int)size; i++)
		ca[((array[i] / pos) % 10)] += 1;
	for (i = 0; i < 10; i++)
		ca[i] += ca[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		out[ca[((array[i] / pos) % 10)] - 1] = array[i];
		ca[((array[i] / pos) % 10)] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = out[i];
}
