/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_implementation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:41:41 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/10 10:41:41 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	ft_rra_implementation(t_stacks *stacks)
{
	t_stack	*cursor;
	t_stack	*penultime;
	t_stack	*last_node;

	if (stacks && stacks->a && stacks->a->next)
	{
		cursor = stacks->a;
		penultime = NULL;
		last_node = NULL;
		while (cursor)
		{
			penultime = last_node;
			last_node = cursor;
			cursor = cursor->next;
		}
		penultime->next = NULL;
		last_node->next = stacks->a;
		stacks->a = last_node;
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_rrb_implementation(t_stacks *stacks)
{
	t_stack	*cursor;
	t_stack	*penultime;
	t_stack	*last_node;

	if (stacks && stacks->b && stacks->b->next)
	{
		cursor = stacks->b;
		penultime = NULL;
		last_node = NULL;
		while (cursor)
		{
			penultime = last_node;
			last_node = cursor;
			cursor = cursor->next;
		}
		penultime->next = NULL;
		last_node->next = stacks->b;
		stacks->b = last_node;
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_rrr_implementation(t_stacks *stacks)
{
	if (stacks && stacks->a && stacks->a->next && stacks->b && stacks->b->next)
	{
		ft_rra_implementation(stacks);
		ft_rrb_implementation(stacks);
		return (1);
	}
	else
	{
		return (0);
	}
}
