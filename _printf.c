#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>


/**
* _printf- Custom printf function to output according to a format.
* @format: Format string containing specifiers (%c, %s, %%).
* Doesn't handle flags, field width, precision, or length.
* Return: Number of characters printed (excluding the null byte used
* to end output of strings)
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
if (*format == '\0')
{
break;
}
switch (*format)
{
case 'c':
count += _putchar(va_arg(args, int));
break;
case 's':
{
char *s = va_arg(args, char *);
if (!s)
s = "(null)";
while (*s)
count += _putchar(*s++);
}
break;
case '%':
count += _putchar('%');
break;
default:

count += _putchar('%');
count += _putchar(*format);
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
