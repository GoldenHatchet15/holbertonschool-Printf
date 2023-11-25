#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include "main.h"

int handle_integer(va_list *args) {
    int num = va_arg(*args, int);
    char buffer[12]; 
    sprintf(buffer, "%d", num); 
    char *s = buffer;
    int count = 0;
    while (*s) {
        count += write(1, s++, 1); 
    }
    return (count);
}

int handle_char(va_list *args) {
    char c = (char)va_arg(*args, int);
    return (write(1, &c, 1));
}

int handle_string(va_list *args) {
    char *s = va_arg(*args, char *);
    int count = 0;
    if (!s)
        s = "(null)";
    while (*s) {
        count += write(1, s++, 1);
    }
    return (count);
}

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
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
                    count += write(1, format, 1); 
                    break;
            }
            format++;
        } else {
            count += write(1, format, 1);
            format++;
        }
    }

    va_end(args);

    return (count);
}