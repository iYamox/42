/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:26:52 by amary             #+#    #+#             */
/*   Updated: 2025/12/21 13:27:21 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

void	ft_free(char **tab, int index)
{
	int	j;

	j = 0;
	while (j < index)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

char	*ft_strndup(const char *str, int start, int end)
{
	int		i;
	char	*tab;

	tab = malloc((end - start + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (start < end)
		tab[i++] = str[start++];
	tab[i] = '\0';
	return (tab);
}

int	fill_tab(char **tab, const char *str, char c)
{
	int	i;
	int	k;
	int	start;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		tab[k] = ft_strndup(str, start, i);
		if (!tab)
			return (ft_free(tab, i), 0);
		k++;
	}
	tab[k] = NULL;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;

	if (!str)
		return (NULL);
	tab = malloc ((ft_count_words(str, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!fill_tab(tab, str, c))
		return (free(tab), NULL);
	return (tab);
}
