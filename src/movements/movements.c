/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:34:52 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/10 10:34:52 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sa(t_stacks *stacks)
{
	ft_sa_implementation(stacks);
	ft_print_message("sa");
}

void	ft_sb(t_stacks *stacks)
{
	ft_sb_implementation(stacks);
	ft_print_message("sb");
}

void	ft_ss(t_stacks *stacks)
{
	ft_ss_implementation(stacks);
	ft_print_message("ss");
}

void	ft_pa(t_stacks *stacks)
{
	ft_pa_implementation(stacks);
	ft_print_message("pa");
}

void	ft_pb(t_stacks *stacks)
{
	ft_pb_implementation(stacks);
	ft_print_message("pb");
}
