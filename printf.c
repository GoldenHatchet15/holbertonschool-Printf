#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Custom printf function to output according to a format.
* @format: Format string containing specifiers (%d, %i).
* Doesn't handle flags, field width, precision, or length.
* Return: Number of characters printed (excluding the null byte
* used to end output of strings).
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
int num;
int digits;
int temp;
int divisor;
int i;

if (!format)
return (-1);

va_start(args, format);

while (*format)
{
if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == '1'))
{
num = va_arg(args, int);
digits = 0;

if(num < 0)
{
count += write(1, "-", 1);
num = -num;
}

if (num == 0)
{
count += write(1, "0", 1);
}
else
{
temp = num;
while (temp > 0)
{
temp /= 10;
digits++;
}
}
divisor = 1;
for (i = 1; i < digits; i++)
divisor *= 10;

while (digits > 0)
{
digits = num / divisor;
count += write(1, &digits + '0', 1);
num %= divisor;
divisor /= 10;
digits--;
}

format++;
}
else
{
count += write(1, format, 1);
}
format++;
}
va_end(args);

return (count);
}
