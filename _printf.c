#include "main.h"
#include <stdarg.h>
#include <string.h>
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	va_list args;

	int count = 0;

	const char *ptr = format;

	va_start(args, format);

	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					fputs(va_arg(args, char*), stdout);
					count += strlen(va_arg(args, char*));
					break;
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
			putchar(*ptr);
			count++;
		}
		ptr++;
	}
	va_end(args);
	return (count);
}	
