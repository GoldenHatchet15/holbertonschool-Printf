#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
return fwrite(1, &c, 1);
}


/**
* _printf - Custom printf function with limited format specifiers.
* @format: Format string containing specifiers (%c, %s, %%).
*          Doesn't handle flags, field width, precision, or length.
*
* Return: Number of characters printed (excluding the null byte used
*         to end output of strings)
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
char c = (char)va_arg(args, int);
putchar(c);
count++;
break;
}
case 's':
{
const char *s = va_arg(args, const char *);
while (*s != '\0')
{
putchar(*s);
s++;
count++;
}
break;
}
case '%':
putchar('%');
count++;
break;
default:
break;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);

return (count);
}
