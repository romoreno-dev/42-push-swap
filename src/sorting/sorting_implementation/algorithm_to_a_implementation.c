/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_to_a_implementation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:23:18 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/16 14:21:22 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static void		ft_set_target_node_a(t_stacks *stacks);
static t_stack	*ft_cost_cheapest_a(t_stacks *stacks, int size_a, int size_b);

static void	ft_set_target_node_a(t_stacks *stacks)
{
	long	closest;
	t_stack	*cursor_a;
	t_stack	*cursor_b;

	cursor_b = stacks->b;
	while (cursor_b)
	{
		closest = LONG_MAX;
		cursor_a = stacks->a;
		while (cursor_a)
		{
			if (cursor_b->value < cursor_a->value && cursor_a->value < closest)
			{
				closest = cursor_a->value;
				cursor_b->target_element = cursor_a;
			}
			cursor_a = cursor_a->next;
		}
		if (closest == LONG_MAX)
		{
			cursor_b->target_element = ft_find_smallest_node(stacks->a);
		}
		cursor_b = cursor_b->next;
	}
}

static t_stack	*ft_cost_cheapest_a(t_stacks *stacks, int size_a, int size_b)
{
	t_stack	*cursor_b;
	t_stack	*cheapest;

	cheapest = NULL;
	cursor_b = stacks->b;
	while (cursor_b)
	{
		cursor_b->cost = ft_get_cost_to_take_to_the_top(cursor_b, size_b)
			+ ft_get_cost_to_take_to_the_top(cursor_b->target_element, size_a);
		if (!cheapest || (cursor_b->cost < cheapest->cost))
		{
			cheapest = cursor_b;
		}
		cursor_b = cursor_b->next;
	}
	return (cheapest);
}

t_stack	*ft_prepare_to_move_a(t_stacks *stacks, int size_a, int size_b)
{
	t_stack	*cheapest;

	ft_set_position(stacks->a);
	ft_set_position(stacks->b);
	ft_set_target_node_a(stacks);
	cheapest = ft_cost_cheapest_a(stacks, size_a, size_b);
	return (cheapest);
}

void	move_a(t_stacks *stacks, t_stack *ch, int sz_a, int sz_b)
{
	if (ch->position <= sz_b / 2 && ch->target_element->position <= sz_a / 2)
		while (stacks->b != ch && stacks->a != ch->target_element)
			ft_rr(stacks);
	else if (ch->position > sz_b / 2 && ch->target_element->position > sz_a / 2)
		while (stacks->b != ch && stacks->a != ch->target_element)
			ft_rrr(stacks);
	sz_a = ft_stack_size(stacks->a);
	sz_b = ft_stack_size(stacks->b);
	ft_set_position(stacks->a);
	ft_set_position(stacks->b);
	while (stacks->a != ch->target_element)
	{
		if (ch->target_element->position <= sz_a / 2)
			ft_ra(stacks);
		else
			ft_rra(stacks);
	}
	ft_pa(stacks);
}
