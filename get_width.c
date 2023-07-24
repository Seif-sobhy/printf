#include "main.h"

/**
 * get_width - detect the width of spaces before printing
 * @format: string which we check.
 * @i: pointer for position of %.
 * @list: list of arguments.
 *
 * Return: w.
 */
int get_width(const char *format, int *i, va_list list)
{
	int ptr_i;
	int s = 0;

	for (ptr_i = *i + 1; format[ptr_i] != '\0'; ptr_i++)
	{
		if (format[ptr_i] >= '0' && format[ptr_i] <= '9')
		{
			s *= 10;
			s += format[ptr_i] - '0';
		}
		else if (format[ptr_i] == '*')
		{
			ptr_i++;
			s = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ptr_i - 1;

	return (s);
}

