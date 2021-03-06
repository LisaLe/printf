#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * format_u - specificer for u
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_u(va_list valist, char *buffer, int *index)
{
	unsigned int i;
	int j, numlen;
	char *num_str;

	i = va_arg(valist, int);
	numlen = num_len(i);

	num_str = malloc(numlen * sizeof(char));

	utos(num_str, i);

	for (i = *index, j = 0; j < numlen; *index += 1, i++, j++)
	{
		if (*index == 1024)
		{
			_write_buffer(buffer, index);
			reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = num_str[j];
	}
}
/**
 * format_h - specificer for h
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_h(va_list valist, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *hexvalues;
	char *hex;

	n = va_arg(valist, int);
	hexvalues = "0123456789abcdef";
	hex = malloc(9 * sizeof(char));

	for (i = 0; n != 0; i++)
	{
		hex[i] = hexvalues[n % 16];
		n /= 16;
	}
	for (i--; i >= 0; *index += 1, i--)
	{
		buffer[*index] = hex[i];
	}

}
/**
 * format_ch - specificer for ch
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_ch(va_list valist, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *hexvalues;
	char *hex;

	n = va_arg(valist, int);
	hexvalues = "0123456789ABCDEF";

	hex = malloc(9 * sizeof(char));

	for (i = 0; n != 0; i++)
	{
		hex[i] = hexvalues[n % 16];
		n /= 16;
	}
	for (i--; i >= 0; *index += 1, i--)
	{
		buffer[*index] = hex[i];
	}

}
/**
 * format_o - specificer for o
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_o(va_list valist, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *octvalues;
	char *oct;

	n = va_arg(valist, int);
	octvalues = "0123456789ABCDEF";

	oct = malloc(12 * sizeof(char));

	for (i = 0; n != 0; i++)
	{
		oct[i] = octvalues[n % 8];
		n /= 8;
	}
	for (i--; i >= 0; *index += 1, i--)
	{
		buffer[*index] = oct[i];
	}
}
/**
 * format_b - specificer for b
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_b(va_list valist, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *binaryvalues;
	char *binary;

	n = va_arg(valist, int);
	binaryvalues = "01";

	binary = malloc(33 * sizeof(char));

	if (n == 0)
	{
		buffer[*index] = '0';
		*index += 1;
	}
	else
	{
		for (i = 0; n != 0; i++)
		{
			binary[i] = binaryvalues[n % 2];
			n /= 2;
		}
		for (i--; i >= 0; *index += 1, i--)
		{
			buffer[*index] = binary[i];
		}
	}
}
