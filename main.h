#ifdef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>


/**
 * struct format - match the conversion specifies for printf
 * @id: type char pointer of the specifiers i.e (i,h)
 * @f: type of pointer to function for the conversion specifier
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int printf_pointer(va_list val);

#endif
