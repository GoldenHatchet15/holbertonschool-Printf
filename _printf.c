#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
* _printf- Custom printf function to output according to a format.
* @format: Format string containing specifiers (%c, %s, %%).
* Doesn't handle flags, field width, precision, or length.
* Return: Number of characters printed (excluding the null byte used
* to end output of strings)
*/

int print_char(va_list args) {
  return (_putchar(va_arg(args, int)));
}

int print_string(va_list args) {
    char *s = va_arg(args, char *);
    int count = 0;
    if (!s) s = "(null)";
    while (*s) {
        count += _putchar(*s++);
    }
    return (count);
}

int print_percent(__attribute__((unused)) va_list args) {
  return (_putchar('%'));
}

typedef struct {
    char specifier;
    int (*f)(va_list);
} format_t;

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    int i;
    format_t formats[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'\0', NULL}
    };

    va_start(args, format);
    
    while (*format) {
        if (*format == '%') {
            format++;
            for (i = 0; formats[i].specifier; i++) {
                if (formats[i].specifier == *format) {
                    count += formats[i].f(args);
                    break;
                }
            }
            if (formats[i].specifier == '\0') {
                count += _putchar('%');
                if (*format != '\0') {
                    count += _putchar(*format);
                }
            }
        } else {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);
    return (count);
}
