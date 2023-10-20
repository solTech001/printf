#include "main.h"
/**
 * _printf - is a function that select the correct function print.
 * @format: identifier to look for.
 * Return: the length of the string
 */
int _printf(const char *format, ...)
{
convert_match m[] = {
	{"%s", printf_string}, {"%c", print_char},
	{"%%", printf_37},
	{"%i", prinf_int}, {"%d", printf_dec}, {"%r", printf_srev},
	{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", prinf_unsigned},
	{"%o", prinf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
	{"%S", printf_exclusive_string}, {"%p", printf_pointer}
};
va_list args;
int i = 0, j, len = 0;
va_start(args, format);
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);
while (format[i] != '\0')
{
j = 13;
while (j >= 0)
{
if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
{
len += m[j].f(args);
i = i + 2;
goto Here;
}
j--;
}
_putchar(format[i]);
len++;
i++;
}
va_end(args);
return (len);
}
