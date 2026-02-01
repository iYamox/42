/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:01:39 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 16:31:04 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (check_args(argv) == 0)
		return (write(2, "Error\n", 6), 1);
	fill_stack(&stack_a, argv);
	index_stack(stack_a);
	ft_push_swap(&stack_a, &stack_b, ft_arg_len(argv));
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
