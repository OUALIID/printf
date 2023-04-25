#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_formatted_string - backup function
 * @format: pointer
 * @args: arg
 * @i: pointer
 * Return: Always 0 (Success)
 */
int print_formatted_string(const char *format, va_list args, int *i)
{
	int count = 0;
	char *s;

	switch (*(format + *i))
	{
	case 'c':
		_putchar(va_arg(args, int));
		count++;
		break;
	case 's':
		s = va_arg(args, char *);
		if (s == NULL)
			s = "(null)";
		while (*s)
		{
			_putchar(*s++);
			count++;
		}
		break;
	case '%':
		_putchar(format[*i]);
		count++;
		break;
	default:
		_putchar('%');
		_putchar(format[*i]);
		count += 2;
		break;
	}
	return (count);
}
/**
 * _printf - printf function for %s %c %
 * @format: the sring format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				return (-1);
			format++;
			count += print_formatted_string(format, args, &i);
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
