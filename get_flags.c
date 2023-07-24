#include "main.h"

/**
 * get_flags - detect the special flags and its position
 * @format:the sample of formatted string
 * @i: pionter of the position.
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	int s, ptr_i;
	int flags = 0;
	const char F_characters[] = {'-', '+', '0', '#', ' ', '\0'};
	const int F_name[] = {F_minus, F_plus, F_zero, F_hash, F_space, 0};

	for (ptr_i = *i + 1; format[ptr_i] != '\0'; ptr_i++)
	{
		for (s = 0; F_characters[s] != '\0'; s++)
			if (format[ptr_i] == F_characters[s])
			{
				flags |= F_name[s];
				break;
			}

		if (F_characters[s] == 0)
			break;
	}

	*i = ptr_i - 1;

	return (flags);
}

