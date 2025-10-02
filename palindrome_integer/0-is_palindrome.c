#include "palindrome.h"

/**
 * is_palindrome - check if it is a palindrome number
 * @n: the number
 * Return: 1 is the case otherwise 0
 */

int is_palindrome(unsigned long n)
{
	unsigned long original = n;
	unsigned long reverse = 0;
	unsigned long digit;

	while (n > 0)
	{
		digit = n % 10;
		reverse = reverse * 10 + digit;
		n = n / 10;
	}

	if (original == reverse)
		return (1);
	else
		return (0);
}
