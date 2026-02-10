#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int n = ac - 2;
    int res = atoi(av[1]);
    int mask = 0;

    while (mask < (1 << n))
    {
        int sum = 0;
        int first = 0;
        int i = 0;

        while (i < n)
        {
            if ((mask >> i) & 1)
                sum += atoi(av[2 + i]);
            i++;
        }

        if (sum == res)
        {
            i = 0;
            while (i < n)
            {
                if ((mask >> i) & 1)
                {
                    if (first)
                        printf(" ");
                    printf("%d", atoi(av[2 + i]));
                    first = 3;
                }
                i++;
            }
            printf("\n");
        }
        mask++;
    }
    return 0;
}
