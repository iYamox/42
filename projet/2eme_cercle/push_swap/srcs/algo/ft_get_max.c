/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:26:09 by amary             #+#    #+#             */
/*   Updated: 2025/12/23 16:49:43 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_get_max(t_stack **stack_a_head)
{
	int		max;
	t_stack	*cpy;

	if (!stack_a_head || !*stack_a_head)
		return (0);
	cpy = *stack_a_head;
	max = cpy->content;
	while (cpy)
	{
		if (max < cpy->content)
			max = cpy->content;
		cpy = cpy->next;
	}
	return (max);
}
