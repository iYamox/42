/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:55:49 by amary             #+#    #+#             */
/*   Updated: 2025/12/29 16:09:42 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_push(t_stack **stack_b, t_stack **stack_a, int index, int min)
{
	t_stack	*cpy;
	int		i;

	i = index;
	cpy = *stack_a;
	while (i)
	{
		cpy = cpy->next;
		if ((cpy->next == NULL) && cpy->content == min)
		{
			rra(stack_a);
			pb(stack_b, stack_a);
			return ;
		}
		i--;
	}
	while (index > 0)
	{
		ra(stack_a);
		index--;
	}
	pb(stack_b, stack_a);
	return ;
}
