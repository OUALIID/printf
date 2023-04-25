#include <unistd.h>
/**
 * _putchar - Entry point
 * @c: char
 * Return: Always 0 (Success)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
