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
	char *wildcard = NULL;
	char *match_str = s1;

	while (*s1)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else if (*s2 == '*')
		{
			wildcard = s2;
			match_str = s1;
			s2++;
		}
		else if (wildcard)
		{
			s2 = wildcard + 1;
			match_str++;
			s1 = match_str;
		}
		else
			return (0);
	}
	while (*s2 == '*')
		s2++;
	return (*s2 == '\0');
}
