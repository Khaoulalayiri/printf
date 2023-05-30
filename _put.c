#include "main.h"


/**
* _puts - prints a string with newline 
* @str : the string to print 
*
* Return : void 
*/

int _puts(char *str)
{
    char *a=str;
   
   while (str*)
         _putchar(*str*++);
      return (str - a);
}

/**
* _putchar - write the character c to stdout
* @c: The character to print 
*
* Return: on success 1.
* On error, -1 is returned, and erron is not appropriately.
*/
int _putchar(int c)
{
    statuc int i;
    statuc char buf [OUTPUT_BUF_SIZE];
    if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
    {    
          write(1 , buf, i);
           i = 0;
    } 
    if (c != BUF_FLUSH)
    buf [i++] = c;
  return (1);
}

