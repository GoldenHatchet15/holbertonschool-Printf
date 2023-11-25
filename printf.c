#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function to output according to a format.
 * @format: Format string containing specifiers (%c, %s, %%, %d, %i).
 * Return: Number of characters printed (excluding the null byte used to end output of strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, num, temp, digits, i, divisor;
    char digit_char;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        {
            num = va_arg(args, int);
            digits = 0;

            if (num == 0)
            {
                count += write(1, "0", 1);
            }
            else
            {
                if (num < 0)
                {
                    count += write(1, "-", 1);
                    if (num == INT_MIN)
                    {
		      count += write(1, "2147483648", 10); /* Special case handling */
                        format += 2;
                        continue;
                    }
                    else
                    {
                        num = -num;
                    }
                }

                temp = num;
                while (temp != 0)
                {
                    temp /= 10;
                    digits++;
                }

                divisor = 1;
                for (i = 1; i < digits; i++)
                {
                    divisor *= 10;
                }

                while (divisor > 0)
                {
                    digit_char = (num / divisor) % 10 + '0';
                    count += write(1, &digit_char, 1);
                    num %= divisor;
                    divisor /= 10;
                }
            }

            format += 2;
        }
        else if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
		  digit_char = (char)va_arg(args, int); /* handle char */
                    count += write(1, &digit_char, 1);
                    break;
                case 's':
                {
		  char *s = va_arg(args, char *); /* handle string */
                    if (!s)
                        s = "(null)";
                    while (*s)
                        count += write(1, s++, 1);
                    break;
                }
                case '%':
		  count += write(1, "%", 1); /* handle %% */
                    break;
                default:
		  count += write(1, format, 1); /* handle unrecognized specifiers */
                    break;
            }
            format++;
        }
        else
        {
            count += write(1, format, 1);
            format++;
        }
    }

    va_end(args);

    return (count);
}
