/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_min_in_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:57:23 by amary             #+#    #+#             */
/*   Updated: 2025/12/29 16:46:07 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_min_in_b(t_stack **stack_b_head, t_stack **stack_a)
{
	t_stack	*cpy;
	int		i;
	int		min;

	if (!*stack_a || !stack_a)
		return ;
	cpy = *stack_a;
	min = get_min(*stack_a);
	i = 0;
	while (cpy)
	{
		if (cpy->content == min)
		{
			rotate_push(stack_b_head, stack_a, i, min);
			return ;
		}
		i++;
		cpy = cpy->next;
	}
	return ;
}
