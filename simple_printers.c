#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number of bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start != stop && *start != '\0' && start != except)
	{
		sum += _putchar(*start);
		start++;
	}

	return (sum);
}

/**
 * print_rev - prints string in reverse
 * @ap: va_list containing the string
 * @params: the parameters struct
 *
 * Return: number of bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
	int sum = 0;
	char *str = va_arg(ap, char *);

	(void)params;

	if (str != NULL)
	{
		int len = 0;

		while (str[len] != '\0')
		{
			len++;
		}

		for (int i = len - 1; i >= 0; i--)
		{
			sum += _putchar(str[i]);
		}
	}

	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @ap: va_list containing the string
 * @params: the parameters struct
 *
 * Return: number of bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
	int count = 0;
	char *str = va_arg(ap, char *);

	(void)params;

	if (str != NULL)
	{
		char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

		for (int i = 0; str[i] != '\0'; i++)
		{
			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
			{
				int index = str[i] - (str[i] >= 'a' ? 'a' : 'A');

				count += _putchar(arr[index]);

			}
			else
			{
				count += _putchar(str[i]);
			}
		}
	}

	return (count);
}
