#include "main.h"

/**
 * check_space - checks if the input is all spaces
 * @buff: string input
 * Return: 0 if all spaces
 */
int check_space(char *buff)
{
	size_t i;

	for (i = 0; i < strlen(buff) - 1; i++)
	{
		if (buff[i] == ' ')
		{
			continue;
		}
		else
		{
			return (1);
		}
	}
	return (0);
}
