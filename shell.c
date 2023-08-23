#include "main.h"

/**
 * main - Entry point
 * @ac: command number
 * @av: command line array
 * @env: environment varaiables
 * Return: 0 (success)
 **/
int main(int ac __attribute__((unused)),
		char **av __attribute__((unused)), char **env)
{
	char *arg[10], *buffer = NULL;
	int number, i, pid;
	size_t size = 100;

	while (1)
	{
		if (isatty(0) == 1)
			printf("sash ");
		number = getline(&buffer, &size, stdin);
		switch (check_getline(number, buffer, env))
		{
			case 0:
				exit(0);
			case 1:
			case 2:
				continue;
			default:
				break;
		}
		i = 0;
		arg[0] = strtok(buffer, " \n");
		while (arg[i] != NULL)
		{
			i++;
			arg[i] = strtok(NULL, " \n");
		}
		if (access(arg[0], F_OK)  == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(arg[0], arg, NULL);
			else
				wait(NULL);
		}
	}
	return (0);
}
