#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/* Handler function type */
typedef int (*handler_func)(va_list *);

/**
 * handle_char - Prints a character
 * @args: Argument list pointing to the character to be printed
 * Return: Number of characters printed
 */
int handle_char(va_list *args);

/**
 * handle_string - Prints a string
 * @args: Argument list pointing to the string to be printed
 * Return: Number of characters printed
 */
int handle_string(va_list *args);

/**
 * handle_percent - Prints a percent symbol
 * @args: Argument list, unused in this function
 * Return: Number of characters printed
 */
int handle_percent(va_list *args);

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
{0, NULL} /* Null terminator */
};

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
