/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_is_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:18:33 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 17:31:33 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_is_5(t_stack **stack_a_head, t_stack **stack_b_head)
{
	if (!stack_a_head || !*stack_a_head)
		return ;
	set_min_in_b(stack_b_head, stack_a_head);
	set_min_in_b(stack_b_head, stack_a_head);
	ft_algo_is_3(stack_a_head);
	pa(stack_b_head, stack_a_head);
	pa(stack_b_head, stack_a_head);
	return ;
}
