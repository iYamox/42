/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:37:44 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 16:22:34 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rrr(t_stack **stack_b_head, t_stack **stack_a_head)
{
	rra(stack_a_head);
	rrb(stack_b_head);
	write(1, "rrr\n", 4);
}

t_stack	*new_node(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	push_front(t_stack **head, t_stack *new_node)
{
	if (!new_node || !head)
		return ;
	new_node->next = (*head);
	(*head) = new_node;
}
