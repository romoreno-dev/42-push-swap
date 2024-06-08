/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:20:23 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/10 12:20:23 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_sort_two_numbers(t_stacks *stacks);
static void	ft_sort_three_numbers(t_stacks *stacks);
static void	ft_sort_many_numbers(t_stacks *stacks);

void	ft_sort(t_stacks *stacks)
{
	int	sorted;
	int	size;

	sorted = ft_is_sorted(stacks->a);
	if (sorted)
		return ;
	size = ft_stack_size(stacks->a);
	if (size == 1)
		return ;
	else if (size == 2)
		ft_sort_two_numbers(stacks);
	else if (size == 3)
		ft_sort_three_numbers(stacks);
	else
		ft_sort_many_numbers(stacks);
}

static void	ft_sort_two_numbers(t_stacks *stacks)
{
	ft_sa(stacks);
}

static void	ft_sort_three_numbers(t_stacks *stacks)
{
	t_stack	*biggest_node;

	biggest_node = ft_find_biggest_node(stacks->a);
	if (stacks->a == biggest_node)
	{
		ft_ra(stacks);
	}
	else if (stacks->a->next == biggest_node)
	{
		ft_rra(stacks);
	}
	if (stacks->a->value > (stacks->a->next)->value)
	{
		ft_sa(stacks);
	}
}

static void	ft_sort_many_numbers(t_stacks *stacks)
{
	t_stack	*cheapest;
	t_stack	*smallest;
	int		size_a;
	int		size_b;
	int		size;

	ft_push_all_to_b_leaving_three_in_a(stacks);
	ft_sort_three_numbers(stacks);
	ft_clean_target(stacks);
	while (stacks->b)
	{
		size_a = ft_stack_size(stacks->a);
		size_b = ft_stack_size(stacks->b);
		cheapest = ft_prepare_to_move_a(stacks, size_a, size_b);
		move_a(stacks, cheapest, size_a, size_b);
	}
	ft_set_position(stacks->a);
	smallest = ft_find_smallest_node(stacks->a);
	size = ft_stack_size(stacks->a);
	if (smallest->position <= (size / 2))
		while (stacks->a != smallest)
			ft_ra(stacks);
	else
		while (stacks->a != smallest)
			ft_rra(stacks);
}
