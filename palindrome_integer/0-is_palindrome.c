#include "palindrome.h"

/**
 * is_palindrome - check if it is a palindrome number
 * @n: the number
 * Return: 1 is the case otherwise 0
 */

int is_palindrome(unsigned long n)
{
	char str_n[21];
	char str_n_reverse[21];
	int len, i;

	sprintf(str_n, "%lu", n);
	len = strlen(str_n);

	if (len == 1)
	{
		return (1);
	}

	if (len >= 2)
	{
		for (i = 0; i < len; i++)
		{
			str_n_reverse[i] = str_n[len - 1 - i];
		}
		str_n_reverse[len] = '\0';

		if (strcmp(str_n, str_n_reverse) == 0)
		{
			return (1);
		}
		return (0);
	}

	return (0);
}
