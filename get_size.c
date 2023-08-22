#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @h: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *h)
{
	int curr_p = *h + 1;
	int size = 0;

	if (format[curr_p] == 'l')
		size = S_LONG;
	else if (format[curr_p] == 'h')
		size = S_SHORT;

	if (size == 0)
		*h = curr_p - 1;
	else
		*h = curr_p;

	return (size);
}
