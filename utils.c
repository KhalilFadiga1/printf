#include "main.h"

/**
 * is_printable - Evaluates if char is printable
 * @c: char to be evaluated
 *
 * Return: 1 if is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c <= 127)
		return (1);
	return (0);
}

/**
 * append_hexa_decimal - append ascii in hexadecimal code to buffer
 * @buffer: Array of buffer
 * @i: Index at which to start appending
 * @ascii_code: Ascii code
 *
 * Return: Always 3
 */
int append_hexa_decimal(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format is always two digits long */
	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'X';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i++] = map_to[ascii_code % 16];
	return (3);
}

/**
 * is_digit - Verifies if char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_size_number - Cast numbers to the  specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short) num);
	return ((int) num);
}

/**
 * convert_size_unsgnd - Cast numbers to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value to num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if ( size == S_SHORT)
		return ((unsigned short) num);
	return ((unsigned int) num);
}
