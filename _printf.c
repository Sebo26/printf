#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - The function produces output according to a format.
 * @format: 
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
int i;
va_list ap;
char *str;

if (format == NULL)
{
	return -1;
}

va_start(ap, format);
for (i = 0; format[i] != '\0'; i++)
{
	if (format[i] == '%')
	{
		i++;
		if (format[i] == 'c')
		{
			*str = va_arg(ap, int);
			write(1, &str, 1);
		}
		else if (format[i] == 's')
		{
			*str = va_arg(ap, int);
			write(1, &str, strlen(str));
		}
		return (strlen(str));
	}
}
if (str == NULL)
{
	str = "(null)";
}
va_end(ap);
return (strlen(str));
}
