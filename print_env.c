#include "main.h"

/**
 * print_env - prints environment variables
 * @env: array of environment variables
 * Return: void
 **/
void print_env(char **env)
{
	size_t i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
