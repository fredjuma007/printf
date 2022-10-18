#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /*va_list is fount here*/
#include <stdlib.h> /*mallo, free*/
#include <unistd.h> /* write the buffer*/

/*printf functions*/
int _printf(const char *format, ...); /*the actual printf*/
char *print_s(va_list list);
char *print_c(va_list list);
char *print_d(va_list list);
char *itob(va_list list);
char *rot13(va_list list);
char *rev_string(va_list list); /*reverses the string*/

/*assist functions, mostly custom*/
char* (*get_func(char i))(va_list);
char *create_buffer(void);
#endif
