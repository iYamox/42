/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:04:27 by amary             #+#    #+#             */
/*   Updated: 2025/12/29 16:05:41 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_min(t_stack	*stack_a)
{
	t_stack	*cpy;
	int		min;

	cpy = stack_a;
	min = stack_a->content;
	while (cpy)
	{
		if (min > cpy->content)
			min = cpy->content;
		cpy = cpy->next;
	}
	return (min);
}
