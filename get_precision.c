#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @h: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *h, va_list list)
{
	int curr_p = *h + 1;
	int precision = -1;

	if (format[curr_p] != '.')
		return (precision);

	precision = 0;

	for (curr_p += 1; format[curr_p] != '\0'; curr_p++)
	{
		if (is_digit(format[curr_p]))
		{
			precision *= 10;
			precision += format[curr_p] - '0';
		}
		else if (format[curr_p] == '*')
		{
			curr_p++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*h = curr_p - 1;

	return (precision);
}
