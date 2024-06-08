/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:50:00 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/16 13:50:00 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	ft_set_position(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->position = i;
		stack = stack->next;
		i++;
	}
}

void	ft_clean_target(t_stacks *stacks)
{
	t_stack	*cursor_a;
	t_stack	*cursor_b;

	cursor_a = stacks->a;
	cursor_b = stacks->b;
	while (cursor_a)
	{
		cursor_a->cost = -1;
		cursor_a->target_element = NULL;
		cursor_a = cursor_a -> next;
	}
	while (cursor_b)
	{
		cursor_b->cost = -1;
		cursor_b->target_element = NULL;
		cursor_b = cursor_b -> next;
	}
}

int	ft_get_cost_to_take_to_the_top(t_stack *stack_element, int stack_size)
{
	int	median;

	median = stack_size / 2;
	if (stack_element->position <= median)
	{
		return (stack_element->position);
	}
	else
	{
		return (stack_size - stack_element->position);
	}
}
