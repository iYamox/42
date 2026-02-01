/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_is_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:17:08 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 17:31:41 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_is_3(t_stack **stack_a_head)
{
	int		max;
	t_stack	*cpy;

	max = ft_get_max(stack_a_head);
	cpy = *stack_a_head;
	if (cpy->content == max)
	{
		ra(stack_a_head);
		if ((*stack_a_head)->content > (*stack_a_head)->next->content)
			sa(stack_a_head);
		return ;
	}
	while (cpy->next != NULL)
		cpy = cpy->next;
	if (cpy->content == max)
	{
		if ((*stack_a_head)->content > (*stack_a_head)->next->content)
			sa(stack_a_head);
		return ;
	}
	ft_max_is_mid(stack_a_head, max);
	return ;
}
