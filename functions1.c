#include "main.h"

/***************************PRINT UNSIGNED NUMBERS**************/

/**
 * print_unsigned - Prints an unsigned number
 * @types: list of argument
 * @buffer: Buffer array to handle print
 * @flags: Calculating active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE -1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/****************************PRINT UNSIGNED NUMBER IN OCTAL*******/

/**
 * print_octal - print an unsigned number in octal notation
 * @types: List of argument
 * @buffer: Buffer array to handle print
 * @flags: Calculating active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size);
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int int_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && int_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************************PRINT UNSIGNED NUMBER IN HEXADECIMAL**************/

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculating active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifiers
 *
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'x'
				width, precision, size));
}

/******************PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL***********/

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculating active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifiers
 *
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags,
				'X', width, precision, size));
}

/******************PRINT HEXX NUMBER IN LOWER OR UPPER********************/

/**
 * print_hexa - Prints hexadecimal number in lower or upper
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculating active flags
 * @map_to: arrays of numbers to map the number to
 * @flag_ch: Calculating active flags
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flags_ch, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int int_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num > 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && int_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, with, precision, size));
}
