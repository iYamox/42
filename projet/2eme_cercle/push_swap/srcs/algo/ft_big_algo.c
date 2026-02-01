/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:19:49 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 17:45:43 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	define_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	return (40);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk;
	int	target;
	int	pushed;

	chunk = define_chunk_size(size);
	target = chunk;
	pushed = 0;
	while (pushed < size)
	{
		if ((*stack_a)->index <= target)
		{
			pb(stack_b, stack_a);
			pushed++;
			if (*stack_b && (*stack_b)->index < target - (chunk / 2))
				rb(stack_b);
			if (pushed == target)
				target += chunk;
		}
		else
			ra(stack_a);
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		bring_max_to_top(stack_b);
		pa(stack_b, stack_a);
	}
}

void	ft_big_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	size = stack_size(*stack_a);
	push_to_b(stack_a, stack_b, size);
	push_back_to_a(stack_a, stack_b);
}
