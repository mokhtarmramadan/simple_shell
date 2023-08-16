#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>

int check_space(char *buff);
char *parce(char *s);

/**
 * main - Entry point
 * Return: 0 (success)
 **/
int main(void)
{
	char *arg[10], *buffer, *delim, *token;
	int number, i;
	size_t size = 100;
	pid_t pid;

	delim = " \n";
	buffer = NULL;
	while (1)
	{
		if (isatty(0) == 1)
			printf("#cisfun$ ");
		number = getline(&buffer, &size, stdin);
		if (number == EOF || number == -1)
		{
			free(buffer);
			write(0, "\n", 2);
			exit(0);
		}
		if (check_space(buffer) == 0)
		{
			continue;
 		}

		token = strtok(buffer, delim);
		arg[0] = parce(token);
		i = 1;
		while (token != NULL)
		{
			token = strtok(NULL, delim);
			arg[i] = token;
			i++;
		}
		pid = fork();
		if (pid == 0)
		{
			number = execve(arg[0], arg, NULL);
			if (number == -1)
			{
				free(buffer);
				perror("./shell");
				exit(0);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	free(buffer);
	return (0);
}

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

/**
 * parce - adds /bin/ if needed
 * @s: string passed
 * Return: a new string with /bin/ if needec
 */
char *parce(char *s)
{
	char *arg;
	int len;

	if (strstr(s, "/bin/") != NULL)
	{
		return (s);
	}
	else
	{
		len = strlen(s) + 5;
		arg = malloc(sizeof(char) * len);
		if (arg == NULL)
		{
			return (NULL);
		}
		strcpy(arg, "/bin/");
		return (strcat(arg, s));
	}
}
