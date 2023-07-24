#include "main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - the main function
 * @format: f
 * Return: The printed chars.
 */
int _printf(const char *format, ...)
{
	int i, the_printed_ch = 0, the_printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			the_printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			the_printed_ch = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (the_printed_ch == -1)
				return (-1);
			the_printed_chars += the_printed_ch;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (the_printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it  is not 0
 * @buffer: Array of char
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
