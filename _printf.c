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
int i;
va_list ap;
char *s;

if (format == NULL)
{
	return (-1);
}

va_start(ap, format);
for (i = 0; format[i] != '\0'; i++)
{
	if (format[i] == '%')
	{
		i++;
		if (format[i] == 'c')
		{
			char c = va_arg(ap, int);
			write(1, &c, 1);

		}
		else if (format[i] == 's')
		{
			s = va_arg(ap, char*);
			if (s == NULL)
			{
				s = "(null)";
			}
			write(1, s, strlen(s));
		}
	}
	else
	{
		write(1, &format[i], 1);
	}
}

va_end(ap);
return (i);
}

int main(void)
{
	_printf("Nice\n");
	_printf("%c\n", 'K');
	_printf("%%\n");
	_printf("%s\n", "Hello");
	return (0);
}
