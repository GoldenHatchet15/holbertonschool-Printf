#include<stdarg.h>
#include<stdio.h>
#include"main.h"
#include<unistd.h>

/**
*_printf-Customprintffunctiontooutputaccordingtoaformat.
*@format:Formatstringcontainingspecifiers(%c,%s,%%).
*Doesn'thandleflags,fieldwidth,precision,orlength.
*Return:Numberofcharactersprinted(excludingthenullbyteused
*toendoutputofstrings)
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
                    break;
                }
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    
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
