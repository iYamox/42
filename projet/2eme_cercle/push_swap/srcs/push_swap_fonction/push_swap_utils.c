/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:10:53 by amary             #+#    #+#             */
/*   Updated: 2025/12/26 14:25:27 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack **stack_a_head)
{
	t_stack	*tmp;

	if (!stack_a_head || !*stack_a_head || (*stack_a_head)->next == NULL)
		return ;
	tmp = (*stack_a_head)->next;
	(*stack_a_head)->next = tmp->next;
	tmp->next = *stack_a_head;
	*stack_a_head = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b_head)
{
	t_stack	*tmp;

	if (!stack_b_head || !*stack_b_head || (*stack_b_head)->next == NULL)
		return ;
	tmp = (*stack_b_head)->next;
	(*stack_b_head)->next = tmp->next;
	tmp->next = *stack_b_head;
	*stack_b_head = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a_head, t_stack **stack_b_head)
{
	sa(stack_a_head);
	sb(stack_b_head);
	write(1, "ss\n", 3);
}

void	pa(t_stack **stack_b_head, t_stack **stack_a_head)
{
	t_stack	*tmp;

	if (!stack_a_head || !*stack_b_head)
		return ;
	tmp = *stack_b_head;
	*stack_b_head = (*stack_b_head)->next;
	push_front(stack_a_head, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b_head, t_stack **stack_a_head)
{
	t_stack	*tmp;

	if (!stack_b_head || !*stack_a_head)
		return ;
	tmp = *stack_a_head;
	*stack_a_head = (*stack_a_head)->next;
	tmp->next = NULL;
	push_front(stack_b_head, tmp);
	write(1, "pb\n", 3);
}
