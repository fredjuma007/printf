#include "main.h"

/**
 * driver - selector for type of function.
 * @format: string.
 * Description: the function loops through the structs
 * selector[] ment of the struct.
 * Return: a pointer
 * structype selector - Struct
 */

int (*driver(char *format))(char *format, va_list)
{
int i;
/*So Chelsea this besicaly are all the fuctions
 * the project is to handle and evry file
 * will select its function
 * from this file */
structype selector[] = {
{"%c", printc}, /*c */
{"%s", printstr},/*string */
{"%d", printint},/*integer */
{"%i", printint},
{"%%", printpercent},/*this % thing*/
{"%x", printhex},/*hexadecimal*/
{"%X", printHEX},
{"%o", printocta},/*octal*/
{NULL, NULL}
};
/*nullifying the return*/
if (format[1] == ' ' || format[1] == '\0')
return (NULL);
for (i = 0; selector[i].q; i++)
{
if (format[1] == selector[i].q[1])
return (selector[i].u);
}
return (NULL);
}
