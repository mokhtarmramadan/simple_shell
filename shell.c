#include "main.h"

/**
 * main - Entry point
 * Return: 0 (success)
 **/
int main(int ac, char **av, char **env)
{
	char *arg[10], *buffer, *delim, *token;
	int number, i;
	size_t size = 100;
	pid_t pid;
	
	av[ac - 2] = "shell"; 
	delim = " \n";
	buffer = NULL;
	while (1)
	{
		if (isatty(0) == 1)
			printf("#cisfun$ ");
		number = getline(&buffer, &size, stdin);
		switch(check_getline(number, buffer, env))
		{
			case 0:
				exit(0);
			case 1:
			case 2:
				continue;
			default:
				break;
		}

		token = strtok(buffer, delim);
		arg[0] = token;
		if (arg[0] == NULL)
		{
			free(buffer);
			exit(0);
		}
		i = 1;
		while (token != NULL)
		{
			token = strtok(NULL, delim);
			arg[i] = token;
			i++;
		}
		if (access(arg[0], F_OK)  == 0)
		{
			pid = fork();
		
			if (pid == 0)
			{
				number = execve(arg[0], arg, NULL);
				if (number == -1)
				{
					free(buffer);
					perror("./khara");
					exit(0);
				}
			}
			else
			{
				wait(NULL);
			}
		}
	}
	free(buffer);
	return (0);
}
