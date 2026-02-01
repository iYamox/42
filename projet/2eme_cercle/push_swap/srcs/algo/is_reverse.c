/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:20:32 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 17:31:11 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_reverse(t_stack *stack_a)
{
	t_stack	*cpy;
	int		value;
	int		tmp;

	cpy = stack_a;
	value = stack_a->content;
	while (cpy)
	{
		tmp = cpy->next->content;
		if (!(value == tmp + 1))
			return (0);
		cpy = cpy->next;
		value = cpy->content;
	}
	return (1);
}
