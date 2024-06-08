/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_implementation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:41:46 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/10 10:41:46 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	ft_pa_implementation(t_stacks *stacks)
{
	t_stack	*aux;

	if (stacks->b)
	{
		if ((stacks->a))
		{
			aux = stacks->b;
			stacks->b = stacks->b->next;
			aux->next = stacks->a;
			stacks->a = aux;
		}
		else
		{
			stacks->a = stacks->b;
			stacks->b = stacks->b->next;
			stacks->a->next = NULL;
		}
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_pb_implementation(t_stacks *stacks)
{
	t_stack	*aux;

	if (stacks->a)
	{
		if ((stacks->b))
		{
			aux = stacks->a;
			stacks->a = stacks->a->next;
			aux->next = stacks->b;
			stacks->b = aux;
		}
		else
		{
			stacks->b = stacks->a;
			stacks->a = stacks->a->next;
			stacks->b->next = NULL;
		}
		return (1);
	}
	else
	{
		return (0);
	}
}
