#include<stdarg.h>
#include<stdio.h>
#include"main.h"
#include<unistd.h>


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
            /* Check if the next character is the end of the string*/
            if (*format == '\0')
            {
	      break; /* Exit the loop, do not print anything for standalone '%'*/
            }
            switch (*format)
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *);
                        if (str == NULL)
                            str = "(null)";
                        while (*str)
                            count += _putchar(*str++);
                    }
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                default:
		  /* Handle unknown format specifiers*/
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
