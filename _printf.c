#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
* _printf- Custom printf function to output according to a format.
* @format: Format string containing specifiers (%c, %s, %%).
* Doesn't handle flags, field width, precision, or length.
* Return: Number of characters printed (excluding the null byte used
* to end output of strings)
*/



/* Function pointer type for handler functions*/
typedef int (*handler_func)(va_list *);

/* Handler functions*/
int handle_char(va_list *args) {
    return _putchar(va_arg(*args, int));
}

int handle_string(va_list *args) {
    char *s = va_arg(*args, char *);
    int count = 0;
    if (!s)
        s = "(null)";
    while (*s)
        count += _putchar(*s++);
    return (count);
}

int handle_percent(va_list *args) {
  (void)args; /* Unused parameter*/
    return _putchar('%');
}

/* Struct to associate specifiers with handler functions*/
typedef struct {
    char specifier;
    handler_func handler;
} format_specifier;

/* Array of format specifiers and their handlers*/
format_specifier specifiers[] = {
    {'c', handle_char},
    {'s', handle_string},
    {'%', handle_percent},
    {0, NULL} /* Null terminator*/
};

/* Custom printf function*/

int _printf(const char *format, ...) {
    va_list args;
    int count = 0, i;
    
    if (!format)
        return (-1);

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == '\0') {
	      /* Do not print anything and break*/
                break;
            }
            for (i = 0; specifiers[i].specifier; i++) {
                if (*format == specifiers[i].specifier) {
                    count += specifiers[i].handler(&args);
                    break;
                }
            }
            if (!specifiers[i].specifier) {
                count += _putchar('%');
                count += _putchar(*format);
            }
        } else {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);
    return (count);
}



