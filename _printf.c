#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_formatted_string - takes in the format string and argument list
 * @format: the format string
 * @args: the argument list
 * Return: the number of characters printed
 */
int print_formatted_string(const char *format, va_list args)
{
	int count = 0;
	char *s;

	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					_putchar((char)va_arg(args, int));
					count++;
					break;
				case 's':
					s = va_arg(args, char*);
					while (*s)
					{
						_putchar(*s);
						s++;
						count++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	return (count);
}
/**
 * _printf - produces output according to a format
 * @format: the sring format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	count = print_formatted_string(format, args);
	va_end(args);
	return (count);
}
