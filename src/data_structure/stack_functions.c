/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:37:49 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/10 11:37:49 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*ft_find_biggest_node(t_stack *a)
{
	t_stack	*biggest_node;

	if (a)
	{
		biggest_node = a;
		a = a->next;
	}
	while (a)
	{
		if (a->value > biggest_node->value)
		{
			biggest_node = a;
		}
		a = a->next;
	}
	return (biggest_node);
}

t_stack	*ft_find_smallest_node(t_stack *a)
{
	t_stack	*smallest_node;

	if (a)
	{
		smallest_node = a;
		a = a->next;
	}
	while (a)
	{
		if (a->value < smallest_node->value)
		{
			smallest_node = a;
		}
		a = a->next;
	}
	return (smallest_node);
}

t_stack	*ft_last_node(t_stack *stack)
{
	t_stack	*last_node;

	last_node = NULL;
	while (stack)
	{
		last_node = stack;
		stack = stack->next;
	}
	return (last_node);
}

int	ft_is_sorted(t_stack *a)
{
	t_stack	*previous;

	previous = NULL;
	while (a)
	{
		if (previous && previous->value > a->value)
		{
			return (0);
		}
		previous = a;
		a = a->next;
	}
	return (1);
}
