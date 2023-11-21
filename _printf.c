#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>

/**
 * _printf - Custom printf function to output according to a format.
 * @format: Format string containing specifiers (%c, %s, %%).
 *          Doesn't handle flags, field width, precision, or length.
 * Return: Number of characters printed (excluding the null byte used
 *         to end output of strings)
 */

int main(void)
{

int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += _putchar(va_arg(args, int));
break;
case 's':
{
char *s = va_arg(args, char *);
while (s && *s)
{
count += _putchar(*s++);
}
}
break;
case '%':
count += _putchar('%');
break;
default:
break;
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
return(0);
}
