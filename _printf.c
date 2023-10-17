#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - The function produces output according to a format.
 * @format: format of text printed.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
int counter = 0;
int length;
va_list ap;
char *s;

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
		counter++;
	}
	else
	{
		format++;
		if (*format == '\0')
		{
			break;
		}
	if (*format == '%')
	{
		write(1, format, 1);
		counter++;
	}
	else if (*format == 'c')
	{
		char c = va_arg(ap, int);
		write(1, &c, 1);
		counter++;
	}
	else if (*format == 's')
	{
		s = va_arg(ap, char*);
		length = strlen(s);
		write(1, s, length);
		counter += length;
	}
	}
	format++;
}

va_end(ap);
return (counter);
}

int main(void)
{
	_printf("Nice\n");
	_printf("%c\n", 'K');
	_printf("%%\n");
	_printf("%s\n", "Hello");
	return (0);
}
