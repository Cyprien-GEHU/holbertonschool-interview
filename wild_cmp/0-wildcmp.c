#include "holberton.h"
#include <stdlib.h>

/**
 * wildcmp - compare to strings with wildcard support
 * @s1: string 1
 * @s2: string 2 with wildcard support
 *
 * Return: 1 if the case, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		if (*s1 != '\0')
			return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));

		return (wildcmp(s1, s2 + 1));
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
