/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:09:13 by amary             #+#    #+#             */
/*   Updated: 2025/12/21 19:36:55 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	my_free(char **tmp)
{
	int	j;

	if (!tmp)
		return ;
	j = 0;
	while (tmp[j])
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
}

int	ft_arg_count(char *str, char c)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (!str[i])
			break ;
		while (str[i] && str[i] != c)
			i++;
		k++;
	}
	return (k);
}

int	ft_arg_len(char **argv)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (argv[++j])
		count += ft_arg_count(argv[j], ' ');
	return (count);
}

int	check_args(char **argv)
{
	char	**tmp;
	int		j;

	j = 1;
	while (argv[j])
	{
		tmp = ft_split(argv[j], ' ');
		if (!(verif_format(tmp)))
			return (my_free(tmp), 0);
		my_free(tmp);
		j++;
	}
	if (ft_check_doublon(argv) == 0)
		return (0);
	else
		return (1);
}

int	verif_format(char **str)
{
	if (!(ft_isdigit(str)))
		return (0);
	if (!(ft_check_limits(str)))
		return (0);
	return (1);
}
