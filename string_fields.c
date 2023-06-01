#include "main.h"
#include <ctype.h>

/**
* get_width - gets the width from the format string
* @p: the format string
* @params: the parameters struct
* @ap: the argument pointer
*
* Return: new pointer
*/
char *get_width(char *p, params_t *params, va_list ap)
{
	int w = 0;

	if (*p == '*')
	{
		w = va_arg(ap, int);
		p++;
	}
	else
	{
		while (isdigit((unsigned char)*p))
		{
			w = w * 10 + (*p - '0');
			p++;
		}
	}

	params->width = w;
	return (p);
}

/**
* get_precision - gets the precision from the format string
* @p: the format string
* @params: the parameters struct
* @ap: the argument pointer
*
* Return: new pointer
*/
char *get_precision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);

	p++;

	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (isdigit((unsigned char)*p))
		{
			d = d * 10 + (*p - '0');
			p++;
		}
	}

	params->precision = d;
	return (p);
}
