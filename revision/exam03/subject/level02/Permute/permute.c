#include <unistd.h>

void    swap(char *a, char *b)
{
    char tmp;

	tmp = *a;
    *a = *b;
    *b = tmp;
}

void    sort(char *s)
{
    int i, j;

    i = 0;
    while (s[i])
    {
        j = i + 1;
        while (s[j])
        {
            if (s[i] > s[j])
                swap(&s[i], &s[j]);
            j++;
        }
        i++;
    }
}

void    permute(char *s, int i, int len)
{
    int j;

    if (i == len)
    {
        write(1, s, len);
        write(1, "\n", 1);
        return;
    }
    j = i;
    while (j < len)
    {
        if (j == i || s[j] != s[i])
        {
            swap(&s[i], &s[j]);
            permute(s, i + 1, len);
            swap(&s[i], &s[j]);
        }
        j++;
    }
}

int    main(int ac, char **av)
{
    int len = 0;

    if (ac != 2)
        return (0);
    while (av[1][len])
        len++;
    sort(av[1]);
    permute(av[1], 0, len);
    return (0);
}
