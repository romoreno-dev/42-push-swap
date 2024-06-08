/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_implementation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:41:38 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/10 10:41:38 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	ft_ra_implementation(t_stacks *stacks)
{
	t_stack	*last_node;

	if (stacks && stacks->a && stacks->a->next)
	{
		last_node = ft_last_node(stacks->a);
		last_node->next = stacks->a;
		stacks->a = stacks->a->next;
		last_node->next->next = NULL;
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_rb_implementation(t_stacks *stacks)
{
	t_stack	*last_node;

	if (stacks && stacks->b && stacks->b->next)
	{
		last_node = ft_last_node(stacks->b);
		last_node->next = stacks->b;
		stacks->b = stacks->b->next;
		last_node->next->next = NULL;
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_rr_implementation(t_stacks *stacks)
{
	if (stacks && stacks->a && stacks->a->next && stacks->b && stacks->b->next)
	{
		ft_ra_implementation(stacks);
		ft_rb_implementation(stacks);
		return (1);
	}
	else
	{
		return (0);
	}
}
