/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:23:10 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 17:32:37 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get_min_node(t_stack *stack)
{
	t_stack	*min;

	min = NULL;
	while (stack)
	{
		if (stack->index == -1)
		{
			if (!min || stack->content < min->content)
				min = stack;
		}
		stack = stack->next;
	}
	return (min);
}
