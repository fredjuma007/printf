#include "main.h"

/**
 * check_buffer_overflow - if code over buffer the space
 * print everything then revert back to 0
 * @buffer: holds the string to print
 * @len: position in buffer
 * Return: lenght position
 */

int check_buffer_overflow(char *buffer, int len)
{
	if (len > 1020)
	{
		write(1, buffer, len);
		len = 0;
	}
	return(len); /*lenth position*/
}

/**_printf - custom version of printf
 * @format: intioal string with all identifiers
 * Return: string with identifies expanded
 */

int _printf(const char *format, ...)
	{
	int len = 0, total_len = 0, i = 0, j = 0;
	va_list list;
	char *buffer, *str;
	char* (*f)(va_list);

	if (format == NULL)
		return (-1);

	buffer = create_buffer();
	if (buffer == NULL)
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%') /* copy format into buffer until '%' */
		{
			len = check_buffer_overflow(buffer, len);
			buffer[len++] = format[i++];
			total_len++;
		}
		else /* if %, find function */
		{
			i++;
			if (format[i] == '\0') /* handle single ending % */
			{
				va_end(list);
				free(buffer);
				return (-1);
			}
			if (format[i] == '%') /* handle double %'s */
			{
				len = check_buffer_overflow(buffer, len);
				buffer[len++] = format[i];
				total_len++;
			}
			else
			{
				f = get_func(format[i]); /* grab function */
				if (f == NULL)  /* handle fake id */
				{
					len = check_buffer_overflow(buffer, len);
					buffer[len++] = '%'; total_len++;
					buffer[len++] = format[i]; total_len++;
				}
				else /* return string, copy to buffer */
				{
					str = f(list);
					if (str == NULL)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = '\0';
						total_len++;
					}
					j = 0;
					while (str[j] != '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = str[j];
						total_len++; j++;
					}
					free(str);
				}
			} i++;
		}
	}
	
	return (total_len);
}

/**
 * main - sample main program
 * Return: 0 on sucess
 */
int main(void)
{
	_printf("\n\n\nMike testing One two This is what it can do\n\n\n");
	sleep(1);
	_printf("\nPrinting Strings, Characters, and Numbers...... %s %c%drld\n\n", "Hello", 'W', 0);
	sleep(1);
	_printf("\n\n             = )                  \n\n\n");
	return (0);
}
