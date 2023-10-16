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
			*str = va_arg(ap, char);
			write(1, &str);
		}
		else if (format[i] == 's')
		{
			*str = va_arg(ap, char);
			write(1, &str);
		}
		if (str == NULL)
		{
			str = "(null)";
		}
		return (strlen(str));
	}
}
va_end(ap);
return (0);
}
