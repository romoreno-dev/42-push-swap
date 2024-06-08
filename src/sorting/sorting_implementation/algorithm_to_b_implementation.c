/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_to_b_implementation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:26:38 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/16 14:21:58 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static void		ft_set_target_node_b(t_stacks *stacks);
static t_stack	*ft_cost_cheapest_b(t_stacks *stacks, int size_a, int size_b);
static t_stack	*ft_prepare_to_move_b(t_stacks *stacks, int size_a, int size_b);
static void		move_b(t_stacks *stacks, t_stack *ch, int sz_a, int sz_b);

void	ft_push_all_to_b_leaving_three_in_a(t_stacks *stacks)
{
	int		size;
	int		size_a;
	int		size_b;
	int		pushed;
	t_stack	*cheapest;

	pushed = 0;
	size = ft_stack_size(stacks->a);
	while (size > 3 && pushed < 2)
	{
		ft_pb(stacks);
		size--;
		pushed++;
	}
	while (size > 3)
	{
		size_a = ft_stack_size(stacks->a);
		size_b = ft_stack_size(stacks->b);
		cheapest = ft_prepare_to_move_b(stacks, size_a, size_b);
		move_b(stacks, cheapest, size_a, size_b);
		size--;
		pushed++;
	}
}

static void	ft_set_target_node_b(t_stacks *stacks)
{
	long	closest;
	t_stack	*cursor_a;
	t_stack	*cursor_b;

	cursor_a = stacks->a;
	cursor_b = stacks->b;
	while (cursor_a)
	{
		closest = LONG_MIN;
		cursor_b = stacks->b;
		while (cursor_b)
		{
			if (cursor_a->value > cursor_b->value && cursor_b->value > closest)
			{
				closest = cursor_b->value;
				cursor_a->target_element = cursor_b;
			}
			cursor_b = cursor_b->next;
		}
		if (closest == LONG_MIN)
		{
			cursor_a->target_element = ft_find_biggest_node(stacks->b);
		}
		cursor_a = cursor_a->next;
	}
}

static t_stack	*ft_cost_cheapest_b(t_stacks *stacks, int size_a, int size_b)
{
	t_stack	*cursor_a;
	t_stack	*cheapest;

	cheapest = NULL;
	cursor_a = stacks->a;
	while (cursor_a)
	{
		cursor_a->cost = ft_get_cost_to_take_to_the_top(cursor_a, size_a)
			+ ft_get_cost_to_take_to_the_top(cursor_a->target_element, size_b);
		if (!cheapest || (cursor_a->cost < cheapest->cost))
		{
			cheapest = cursor_a;
		}
		cursor_a = cursor_a->next;
	}
	return (cheapest);
}

t_stack	*ft_prepare_to_move_b(t_stacks *stacks, int size_a, int size_b)
{
	t_stack	*cheapest;

	ft_set_position(stacks->a);
	ft_set_position(stacks->b);
	ft_set_target_node_b(stacks);
	cheapest = ft_cost_cheapest_b(stacks, size_a, size_b);
	return (cheapest);
}

static void	move_b(t_stacks *stacks, t_stack *ch, int sz_a, int sz_b)
{
	if (ch->position <= sz_a / 2 && ch->target_element->position <= sz_b / 2)
		while (stacks->a != ch && stacks->b != ch->target_element)
			ft_rr(stacks);
	else if (ch->position > sz_a / 2 && ch->target_element->position > sz_b / 2)
		while (stacks->a != ch && stacks->b != ch->target_element)
			ft_rrr(stacks);
	sz_a = ft_stack_size(stacks->a);
	sz_b = ft_stack_size(stacks->b);
	ft_set_position(stacks->a);
	ft_set_position(stacks->b);
	while (stacks->a != ch)
	{
		if (ch->position <= sz_a / 2)
			ft_ra(stacks);
		else
			ft_rra(stacks);
	}
	while (stacks->b != ch->target_element)
	{
		if (ch->target_element->position <= sz_b / 2)
			ft_rb(stacks);
		else
			ft_rrb(stacks);
	}
	ft_pb(stacks);
}
