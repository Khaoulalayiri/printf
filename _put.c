#include "main.h"
#include <unistd.h> /* Added for write() function */

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1 is returned.
*         On error, -1 is returned, and errno is set appropriately.
**/
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	buf[i++] = c;

	return (1);
}

/**
* _puts - prints a string with a newline
* @str: The string to print
*
* Return: void
*/
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}

	_putchar('\n');
}

