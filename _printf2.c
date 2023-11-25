#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/* Handler function type */
typedef int (*handler_func)(va_list *);

/* Handle character specifier */
int handle_char(va_list *args) {
    return (_putchar(va_arg(*args, int)));
}

/* Handle string specifier */
int handle_string(va_list *args) {
    char *s = va_arg(*args, char *);
    int count = 0;

    if (!s)
        s = "(null)";
    while (*s)
        count += _putchar(*s++);
    return (count);
}

/* Handle percent specifier */
int handle_percent(va_list *args) {
    (void)args; /* Unused parameter */
    return (_putchar('%'));
}

/* Handle integer specifier */
int handle_int(va_list *args) {
    int num = va_arg(*args, int);
    char buffer[11]; 
    sprintf(buffer, "%d", num);
    char *s = buffer;
    int count = 0;
    while (*s) {
        count += _putchar(*s++);
    }
    return count;
}

/**
 * struct format_specifier - Associates format specifiers with handler functions
 * @specifier: Character representing the format specifier
 * @handler: Function pointer to the handler function for the specifier
 */
typedef struct format_specifier {
    char specifier;
    handler_func handler;
} format_specifier;

/* Array of format specifiers and their handlers */
format_specifier specifiers[] = {
    {'c', handle_char},
    {'s', handle_string},
    {'%', handle_percent},
    {'d', handle_int},
    {'i', handle_int},
    {0, NULL} /* Null terminator */
};

/* Custom printf function */
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
                count += _putchar('%'); 
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
