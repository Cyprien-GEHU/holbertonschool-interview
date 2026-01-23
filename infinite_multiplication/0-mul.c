#include "holberton.h"
#include <stdlib.h>

/**
 * print_error - print message error and exit status 98
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * check_digit - check if the argurment is a digit
 * @n: the digit
 * Return: 0 is not a digit otherwise 1
 */
int check_digit(char *n)
{
	int count =  0;

	while (n[count])
	{
		if (n[count] < '0' || n[count] > '9')
			return (0);
		count++;
	}
	return (1);
}

/**
 * _strlen - function to see the length of the argument
 * @n: the argurment
 * Return: the length of argument
 */
int _strlen(char *n)
{
	int len = 0;

	while (n[len])
		len++;

	return (len);
}

/**
 * print_result - print with putchar the result
 * @result: the result of multiplication
 * @len: the lenght of the result
 */
void print_result(int *result, int len)
{
	int x = 0;

	while (x < len && result[x] == 0)
		x++;

	if (x == len)
	{
		_putchar('0');
		_putchar('\n');
		return;
	}

	while (x < len)
	{
		_putchar(result[x] + '0');
		x++;
	}
	_putchar('\n');
}

/**
 * main - the function to multiplies 2 numbers
 * @argc: number of argument
 * @argv: content of argument
 *
 * Return: 0 if a sucess
 */
int main(int argc, char *argv[])
{
	int *result, lenTotal, n = 0, i, j, mul, carry, len1, len2;

	if (argc != 3)
		print_error();

	if (!check_digit(argv[1]) || !check_digit(argv[2]))
		print_error();

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	lenTotal = len1 + len2;

	result = malloc(sizeof(int) * lenTotal);
	if (!result)
		exit(98);

	while (n < lenTotal)
	{
		result[n] = 0;
		n++;
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j  >= 0; j--)
		{
			mul = (argv[1][i] - '0') * (argv[2][j] - '0');
			mul += result[i + j + 1] + carry;

			carry = mul / 10;
			result[i + j + 1] = mul % 10;
		}
		result[i + j + 1] += carry;
	}

	print_result(result, lenTotal);
	free(result);
	return (0);
}