#include <stdlib.h>
#include <unistd.h>

void	sort(char *str)
{
	int	i;
	int	j;
	char temp;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	perm(char *str, char *result, int *used, int pos, int len)
{
	int	i;

	i = 0;
	if (pos == len)
	{
		while (i < len)
		{
			write(1, &result[i], 1);
			i++;
		}
		write(1, "\n", 1);
		return ;
	}
	i = 0;
	while (i < len)
	{
		if (!used[i])
		{
			used[i] = 1;
			result[pos] = str[i];
			perm(str, result, used, pos + 1, len);
			used[i] = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	int	i;
	char	*result;
	int		len;
	int 	*used;

	i = 0;
	while (argv[1][i])
		i++;
	len = i;
	result = malloc(sizeof(char) * (len + 1));
	used = calloc(len, sizeof(int));
	sort(argv[1]);
	perm(argv[1], result, used, 0, len);
	free(result);
	free(used);
	return (0);
}