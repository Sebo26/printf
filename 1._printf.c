#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
/**
 * _printf - The function produces output according to a format.
 * @format: The format of the number to be printed.
 * Return: Numbers to be printed.
 */
int _printfnum(const char *format, ...)
{
va_list ap;
int length = 0;
int num_length;
if (format == NULL)
{
	return (-1);
}
va_start(ap, format);
while (*format)
{
	if (*format != '%')
	{
		write(1, format, 1);
		length++;
	}
	else
	{
		format++;
		if (*format == 'd' || *format == 'i')
		{
			int d = va_arg(ap, int);
			char numstr[20];

			num_length = sprintf(numstr, "%d", d);
			write(1, numstr, num_length);
			length += num_length;
		}
		else if (*format == 'i')
		{
			int i = va_arg(ap, int);
			char numstr[20];

			num_length = sprintf(numstr, "%i", i);
			write(1, numstr, num_length);
			length += num_length;
		}
	}
	format++;
}
va_end(ap);
return (length);
}
