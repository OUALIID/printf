#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int print_formatted_string(const char* format, va_list args) {
    int count = 0;
    while (*format) {
        if (*format == '%') {
            switch (*(++format)) {
                case 'c':
                    _putchar((char)va_arg(args, int));
                    count++;
                    break;
                case 's':
                    char* s = va_arg(args, char*);
                    for (; *s != '\0'; s++) {
                        _putchar(*s);
                        count++;
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
        else {
            putchar(*format);
            count++;
        }
        format++;
    }
    return count;
}
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);
    
    count = print_formatted_string(format, args);
    va_end(args);
    return count;
}
