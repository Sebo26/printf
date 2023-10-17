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
int num;
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
			num = va_arg(ap, int);
			if (num < 0)
			{
				putchar('-');
				length++;
				num = -num;
			}
			if (num == 0)
			{
				putchar('0');
				length++;
			}
			else
			{
				int reversed = 0;
				while (num > 0)
				{
					int digit = num % 10;
					reversed = reversed * 10 + digit;
					num /= 10;
				}
				while (reversed > 0)
				{
					int digit = reversed % 10;
					putchar('0' + digit);
					length++;
					reversed /= 10;
				}
			}
		}
	}
	format++;
}
va_end(ap);
return (length);
}
