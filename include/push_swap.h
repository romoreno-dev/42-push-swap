/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:13:54 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/08 13:13:54 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "../include/libft/include/libft.h"

typedef struct s_stack_element
{
	struct s_stack_element	*next;
	int						value;
	int						position;
	struct s_stack_element	*target_element;
	int						cost;
	int						cheapest;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

int		ft_check_input(char **numbers);

void	ft_print_message(char *str);
void	ft_print_error_message(void);

void	ft_clean_array(char **array);
void	ft_clean_stack(t_stack *stack);

void	ft_sort(t_stacks *stacks);
void	ft_push_all_to_b_leaving_three_in_a(t_stacks *stacks);

t_stack	*ft_prepare_to_move_a(t_stacks *stacks, int size_a, int size_b);
void	move_a(t_stacks *stacks, t_stack *ch, int sz_a, int sz_b);

void	ft_set_position(t_stack *stack);
void	ft_clean_target(t_stacks *stacks);
int		ft_get_cost_to_take_to_the_top(t_stack *stack_element, int stack_size);

int		ft_stack_size(t_stack *stack);
t_stack	*ft_new_node(int value);
t_stack	*ft_find_biggest_node(t_stack *a);
t_stack	*ft_find_smallest_node(t_stack *a);
t_stack	*ft_last_node(t_stack *stack);
int		ft_is_sorted(t_stack *a);

t_stack	*ft_init_stack(int array_size, char **input_array);
t_stack	*ft_fill_stack(char **numbers);

int		ft_integer_overflow(long number);
int		ft_is_repeated(long l, long *list, int size_list);
long	ft_atol(char *str);
int		ft_quantity(char **numbers);

void	ft_sa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ft_ss(t_stacks *stacks);
void	ft_pa(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);
void	ft_ra(t_stacks *stacks);
void	ft_rb(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);
void	ft_rra(t_stacks *stacks);
void	ft_rrb(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);
int		ft_sa_implementation(t_stacks *stacks);
int		ft_sb_implementation(t_stacks *stacks);
int		ft_ss_implementation(t_stacks *stacks);
int		ft_pa_implementation(t_stacks *stacks);
int		ft_pb_implementation(t_stacks *stacks);
int		ft_ra_implementation(t_stacks *stacks);
int		ft_rb_implementation(t_stacks *stacks);
int		ft_rr_implementation(t_stacks *stacks);
int		ft_rra_implementation(t_stacks *stacks);
int		ft_rrb_implementation(t_stacks *stacks);
int		ft_rrr_implementation(t_stacks *stacks);

#endif
