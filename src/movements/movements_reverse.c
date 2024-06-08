/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:38:09 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/16 12:38:09 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_ra(t_stacks *stacks)
{
	ft_ra_implementation(stacks);
	ft_print_message("ra");
}

void	ft_rb(t_stacks *stacks)
{
	ft_rb_implementation(stacks);
	ft_print_message("rb");
}

void	ft_rr(t_stacks *stacks)
{
	ft_rr_implementation(stacks);
	ft_print_message("rr");
}
