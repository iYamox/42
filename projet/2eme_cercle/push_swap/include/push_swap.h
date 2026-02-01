/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:07:19 by amary             #+#    #+#             */
/*   Updated: 2025/12/30 17:33:12 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

void	push_front(t_stack **head, t_stack *new_node);
void	sa(t_stack **stack_a_head);
void	sb(t_stack **stack_b_head);
void	ss(t_stack **stack_a_head, t_stack **stack_b_head);
void	pa(t_stack **stack_b_head, t_stack **stack_a_head);
void	pb(t_stack **stack_b_head, t_stack **stack_a_head);
void	ra(t_stack **stack_a_head);
void	rb(t_stack **stack_b_head);
void	rr(t_stack **stack_a_head, t_stack **stack_b_head);
void	rra(t_stack **stack_a_head);
void	rrb(t_stack **stack_b_head);
void	rrr(t_stack **stack_b_head, t_stack **stack_a_head);
int		ft_arg_len(char **argv);
int		ft_arg_count(char *str, char c);
char	**ft_split(char const *str, char c);
void	my_free(char **tmp);
int		check_args(char **argv);
int		verif_format(char **str);
int		ft_isdigit(char **argv);
int		ft_check_limits(char **arg);
int		ft_check_doublon(char **arg);
void	ft_print_list(t_stack *stack_a);
long	ft_atoi(char *str);
int		ft_strlen(char *str);
void	fill_stack(t_stack **stack_a_head, char **argv);
int		is_doublon(int *tab, int size);
t_stack	*new_node(int content);
void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int stack_a_size);
int		*ft_fill_tab(int *tab, int size, char **argv);
int		is_trier(int *tab, int size);
void	ft_algo_is_3(t_stack **stack_a_head);
int		ft_get_max(t_stack **stack_a_head);
void	ft_algo_is_5(t_stack **stack_a_head, t_stack **stack_b_head);
void	ft_big_algo(t_stack **stack_a_head, t_stack **stack_b_head);
void	ft_max_is_mid(t_stack **stack_a, int max);
void	set_min_in_b(t_stack **stack_b_head, t_stack **stack_a);
void	rotate_push(t_stack **stack_b, t_stack **stack_a, int index, int min);
int		ft_lst_len(t_stack *stack);
void	free_stack(t_stack *stack);
int		get_min(t_stack	*stack_a);
void	index_stack(t_stack *stack);
t_stack	*get_min_node(t_stack *stack);
int		stack_size(t_stack *stack);
int		get_max_index(t_stack *stack_b);
int		get_position(t_stack *stack_b, int index);
void	bring_max_to_top(t_stack **stack_b);
int		define_chunk_size(int size);
void	push_to_b(t_stack **stack_a, t_stack **stack_b, int size);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);
void	ft_big_algo(t_stack **stack_a, t_stack **stack_b);

#endif