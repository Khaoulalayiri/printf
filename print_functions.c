#include "main.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number of chars printed
 */
int print_char(va_list ap, params_t *params)
{
    char pad_char = ' ';
    unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

    if (params->minus_flag)
        sum += _putchar(ch);

    while (pad++ < params->width)
        sum += _putchar(pad_char);

    if (!params->minus_flag)
        sum += _putchar(ch);

    return (sum);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number of chars printed
 */
int print_int(va_list ap, params_t *params)
{
    long l;

    if (params->l_modifier)
        l = va_arg(ap, long);
    else if (params->h_modifier)
        l = (short int)va_arg(ap, int);
    else
        l = (int)va_arg(ap, int);

    return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number of chars printed
 */
int print_string(va_list ap, params_t *params)
{
    char *str = va_arg(ap, char *);
    char pad_char = ' ';
    unsigned int pad = 0, sum = 0, i = 0, j;

    if (!str)
        str = "(null)";

    j = pad = _strlen(str);
    if (params->precision < pad)
        j = pad = params->precision;

    if (params->minus_flag)
    {
        if (params->precision != UINT_MAX)
            for (i = 0; i < pad; i++)
                sum += _putchar(*str++);
        else
            sum += _puts(str);
    }

    while (j++ < params->width)
        sum += _putchar(pad_char);

    if (!params->minus_flag)
    {
        if (params->precision != UINT_MAX)
            for (i = 0; i < pad; i++)
                sum += _putchar(*str++);
        else
            sum += _puts(str);
    }

    return (sum);
}

/**
 * print_percent - prints percent character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number of chars printed
 */
int print_percent(va_list ap, params_t *params)
{
    (void)ap;
    (void)params;
    return (_putchar('%'));
}

/**
 * _puts - prints a string
 * @str: The string to print
 *
 * Return: number of characters printed
 */
int _puts(char *str)
{
    int count = 0;

    while (*str != '\0')
    {
        if (_putchar(*str) < 0)
            return (-1);
        count++;
        str++;
    }

    return (count);
}

