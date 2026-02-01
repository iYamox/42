/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:10:46 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 17:27:42 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int stack_a_size)
{
	if (stack_a_size == 2)
		sa(stack_a);
	else if (stack_a_size == 3)
		ft_algo_is_3(stack_a);
	else if (stack_a_size <= 5)
		ft_algo_is_5(stack_a, stack_b);
	else if (stack_a_size > 5)
		ft_big_algo(stack_a, stack_b);
	return ;
}
