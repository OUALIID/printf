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
	case 'd':
	case 'i':
		print_int(args, &count);
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
/**
 * print_int_helper - print numbers
 * @num: the number
 * @count: counter
 * Return: counter
 */
int print_int_helper(int *num, int *count)
{
	int digit = 1;

	while (*num / digit >= 10)
		digit *= 10;
	while (digit > 0)
	{
		_putchar('0' + *num / digit);
		*num %= digit;
		digit /= 10;
		(*count)++;
	}
	return (*count);
}
/**
 * print_int - printf function for %i
 * @args: arguments passed
 * @count: a counter
 * Return: void
 */
void print_int(va_list args, int *count)
{
	int num = va_arg(args, int);

	if (num == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		(*count) += 2;
		num = 147483648;
		print_int_helper(&num, count);
	}
	else if (num < 0)
	{
		_putchar('-');
		num = -num;
		(*count)++;
		print_int_helper(&num, count);
	}
	else
		print_int_helper(&num, count);
}
