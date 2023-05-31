#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);

		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}

		start = p;
		p = handle_specifier(p + 1, &params, ap);
		if (p == NULL)
			sum += print_from_to(start, p, 0);
		else
			sum += get_print_func(p, ap, &params);
	}

	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}

/**
 * handle_specifier - handles the format specifier
 * @format: the format string
 * @params: the parameter struct
 * @ap: the va_list
 *
 * Return: pointer to the next character after the specifier
 */
char *handle_specifier(const char *format, params_t *params, va_list ap)
{
	if (*format == '\0')
		return (NULL);

	if (is_valid_specifier(*format))
	{
		params->specifier = *format;
		format++;
	}
	else
	{
		params->specifier = '\0';
		return (NULL);
	}

	if (params->specifier == ' ')
		return ((char *)format);

	format = handle_flags(format, params);

	format = handle_width(format, params, ap);

	format = handle_precision(format, params, ap);

	format = handle_length_modifier(format, params);

	return ((char *)format);
}

/* Rest of the code remains the same */


