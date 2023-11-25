#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_char - Handles the char specifier
 * @args: A va_list of arguments
 * Return: Number of characters printed
 */
int handle_char(va_list *args)
{
    return (_putchar(va_arg(*args, int)));
}

/**
 * handle_string - Handles the string specifier
 * @args: A va_list of arguments
 * Return: Number of characters printed
 */
int handle_string(va_list *args)
{
    char *s = va_arg(*args, char *);
    int count = 0;

    if (!s)
        s = "(null)";
    while (*s)
        count += _putchar(*s++);
    return (count);
}

/**
 * handle_percent - Handles the percent specifier
 * @args: A va_list of arguments
 * Return: Number of characters printed
 */
int handle_percent(va_list *args)
{
    (void)args; /* Unused parameter */
    return (_putchar('%'));
}

/**
 * struct format_specifier - Struct to associate specifiers with handler functions
 * @specifier: The format specifier
 * @handler: The function to handle the specifier
 */
typedef struct format_specifier
{
    char specifier;
    handler_func handler;
} format_specifier;

/**
 * specifiers - Array of format specifiers and their handlers
 */
format_specifier specifiers[] = {
    {'c', handle_char},
    {'s', handle_string},
    {'%', handle_percent},
    {0, NULL} /* Null terminator */
};

/**
 * _printf - Custom printf function to output according to a format
 * @format: Format string containing specifiers (%c, %s, %%)
 * Description: Mimics the standard printf function. It outputs data
 * based on a specified format. This implementation handles a limited
 * set of format specifiers without flags, field width, precision,
 * or length modifiers.
 * Return: Number of characters printed (excluding the null byte
 * used to end output of strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
            {
                count += _putchar('%'); 
                break;
            }
            for (i = 0; specifiers[i].specifier; i++)
            {
                if (*format == specifiers[i].specifier)
                {
                    count += specifiers[i].handler(&args);
                    break;
                }
            }
            if (!specifiers[i].specifier)
            {
                count += _putchar('%');
                count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);
    return (count);
}
