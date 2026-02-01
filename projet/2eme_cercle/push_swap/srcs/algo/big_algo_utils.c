/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:58:44 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 17:01:41 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	get_max_index(t_stack *stack_b)
{
	int	max;

	max = stack_b->index;
	while (stack_b)
	{
		if (stack_b->index > max)
			max = stack_b->index;
		stack_b = stack_b->next;
	}
	return (max);
}

int	get_position(t_stack *stack_b, int index)
{
	int	pos;

	pos = 0;
	while (stack_b)
	{
		if (stack_b->index == index)
			return (pos);
		stack_b = stack_b->next;
		pos++;
	}
	return (pos);
}

void	bring_max_to_top(t_stack **stack_b)
{
	int	max;
	int	pos;
	int	size;

	max = get_max_index(*stack_b);
	pos = get_position(*stack_b, max);
	size = stack_size(*stack_b);
	if (pos <= size / 2)
	{
		while ((*stack_b)->index != max)
			rb(stack_b);
	}
	else
	{
		while ((*stack_b)->index != max)
			rrb(stack_b);
	}
}
