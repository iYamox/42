/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 18:30:26 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 17:30:36 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	fill_stack(t_stack **stack_a_head, char **argv)
{
	int		*tab;
	int		size;
	int		j;

	size = ft_arg_len(argv);
	tab = malloc(size * sizeof(int));
	if (!tab)
		return ;
	ft_fill_tab(tab, size, argv);
	if (is_trier(tab, size) == 1)
	{
		free(tab);
		exit(0);
	}
	j = size - 1;
	while (j >= 0)
		push_front(stack_a_head, new_node(tab[j--]));
	return (free(tab));
}
