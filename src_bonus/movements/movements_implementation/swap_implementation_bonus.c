/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_implementation_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:07:54 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/15 18:07:54 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap_bonus.h"

int	ft_sa_implementation(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*third;

	if (stacks && stacks->a && stacks->a->next)
	{
		first = stacks->a;
		third = stacks->a->next->next;
		stacks->a = stacks->a->next;
		stacks->a->next = first;
		stacks->a->next->next = third;
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_sb_implementation(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*third;

	if (stacks && stacks->b && stacks->b->next)
	{
		first = stacks->b;
		third = stacks->b->next->next;
		stacks->b = stacks->b->next;
		stacks->b->next = first;
		stacks->b->next->next = third;
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_ss_implementation(t_stacks *stacks)
{
	if (stacks && stacks->a && stacks->a->next && stacks->b && stacks->b->next)
	{
		ft_sa_implementation(stacks);
		ft_sb_implementation(stacks);
		return (1);
	}
	else
	{
		return (0);
	}
}
