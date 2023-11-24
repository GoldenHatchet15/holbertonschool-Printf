#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
* main -Entry point
*
* Return: Always 0
*/
int main(void)
{
int len;
int len2;
unsigned int ui;
void *addr;
int myNumber = 42;

len = _printf("Let's try to printf a simple sentence.\n");
len2 = printf("Lets's try to printf a simple sentence.\n");
ui = (unsigned int)INT_MAX + 1024;
addr = (void *)0x7ffe637541f0;

printf("Length:[%d, %i]\n", len2, len2);

printf("Negative:[%d]\n", -762534);

printf("Unsigned:[%u]\n", ui);

printf("Unsigned octal:[%o]\n", ui);

printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

printf("Character:[%c]\n", 'H');

printf("String:[%s]\n", "I am a string !");

printf("Address:[%p]\n", addr);

len2 = printf("Percent:[%%]\n"); 

printf("Len:[%d]\n", len2);

printf("Unknown:[%d]\n", myNumber);
return(0);
}

