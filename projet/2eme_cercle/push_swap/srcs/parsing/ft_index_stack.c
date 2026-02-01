/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:27:05 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 17:32:08 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	index_stack(t_stack *stack)
{
	int		i;
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	i = 1;
	while (i <= size)
	{
		tmp = get_min_node(stack);
		if (tmp)
			tmp->index = i++;
		else
			break ;
	}
}
