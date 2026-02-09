#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int is_balanced(char *s)
{
    int cnt = 0;
    while (*s)
    {
        if (*s == '(')
            cnt++;
        else if (*s == ')')
        {
            cnt--;
            if (cnt < 0)
                return 0;
        }
        s++;
    }
    return cnt == 0;
}

void rip(char *str, int idx, char *current, char **solutions, int *count, int max)
{
    if (idx == (int)strlen(str))
    {
        if (is_balanced(current))
        {
            for (int i = 0; i < *count; i++)
                if (strcmp(solutions[i], current) == 0)
                    return;
            if (*count < max)
                solutions[(*count)++] = strdup(current);
        }
        return;
    }
    current[idx] = str[idx];
    rip(str, idx + 1, current, solutions, count, max);
    current[idx] = ' ';
    rip(str, idx + 1, current, solutions, count, max);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    int len = strlen(argv[1]);
    char *current = malloc(len + 1);
    char **solutions = malloc(sizeof(char *) * 1000); // Max 1000 solutions
    int count = 0;

    current[len] = '\0';
    rip(argv[1], 0, current, solutions, &count, 1000);

    for (int i = 0; i < count; i++)
    {
        puts(solutions[i]);
        free(solutions[i]);
    }
    free(solutions);
    free(current);
    return 0;
}