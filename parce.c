#include "main.h"

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
