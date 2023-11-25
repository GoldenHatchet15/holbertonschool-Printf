#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>

/**
 * handle_integer - Converts an integer to a string and sends it to stdout.
 * @args: A va_list of arguments from _printf.
 * Return: The number of characters printed.
 */
int handle_integer(va_list *args)
{
    int num = va_arg(*args, int);
    char buffer[12];
    char *s;
    int count = 0;

    sprintf(buffer, "%d", num);
    s = buffer;
    while (*s)
    {
        count += write(1, s++, 1);
    }
    return (count);
}

/**
 * handle_char - Sends a character to stdout.
 * @args: A va_list of arguments from _printf.
 * Return: 1 (number of characters printed).
 */
int handle_char(va_list *args)
{
    char c = (char)va_arg(*args, int);
    return (write(1, &c, 1));
}

/**
 * handle_string - Sends a string to stdout.
 * @args: A va_list of arguments from _printf.
 * Return: The number of characters printed.
 */
int handle_string(va_list *args)
{
    char *s = va_arg(*args, char *);
    int count = 0;
    
    if (!s)
        s = "(null)";
    while (*s)
    {
        count += write(1, s++, 1);
    }
    return (count);
}

/**
 * _printf - Outputs a formatted string to stdout.
 * @format: A format string containing specifiers.
 * Return: The number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (!format)
        return (-1);

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'd':
                case 'i':
                    count += handle_integer(&args);
                    break;
                case 'c':
                    count += handle_char(&args);
                    break;
                case 's':
                    count += handle_string(&args);
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, "%", 1);
                    count += write(1, format, 1);
                    break;
            }
            format++;
        }
        else
        {
            count += write(1, format, 1);
            format++;
        }
    }
    va_end(args);
    return (count);
}
