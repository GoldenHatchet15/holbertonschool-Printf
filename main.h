#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _printf(const char *format, ...);
int handle_char(va_list *args);
typedef int (*handler_func)(va_list *);
int handle_string(va_list *args);
int handle_percent(va_list *args);
int handle_int(va_list *args);

/**
 * struct format_specifier - Associates format specifiers with handler functions
 * @specifier: Character representing the format specifier
 * @handler: Function pointer to the handler function for the specifier
 */
typedef struct format_specifier {
char specifier;
handler_func handler;
} format_specifier;


#endif /* MAIN_H */
