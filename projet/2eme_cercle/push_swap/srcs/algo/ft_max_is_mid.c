/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_is_mid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:34:36 by amary             #+#    #+#             */
/*   Updated: 2025/12/23 17:20:13 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_max_is_mid(t_stack **stack_a, int max)
{
	t_stack	*cpy;

	cpy = *stack_a;
	if (cpy->next->content == max)
	{
		sa(stack_a);
		ra(stack_a);
		if (cpy->content > cpy->next->content)
			sa(stack_a);
	}
	return ;
}
