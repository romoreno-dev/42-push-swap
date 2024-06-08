/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:50:31 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/08 12:50:31 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		return (1);
	}
	stacks.a = ft_init_stack(argc - 1, argv + 1);
	stacks.b = NULL;
	if (stacks.a)
	{
		ft_sort(&stacks);
		ft_clean_stack(stacks.a);
	}
}
