/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:09:29 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/15 18:09:29 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	ft_print_message(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_print_error_message(void)
{
	ft_putstr_fd("Error\n", 2);
}
