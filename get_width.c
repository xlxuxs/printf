#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_p;
	int width = 0;

	for (curr_p = *i + 1; format[curr_p] != '\0'; curr_p++)
	{
		if (is_digit(format[curr_p]))
		{
			width *= 10;
			width += format[curr_p] - '0';
		}
		else if (format[curr_p] == '*')
		{
			curr_p++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_p - 1;

	return (width);
}
