/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:12:15 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/15 18:12:15 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diferencia;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			diferencia = s1[i] - s2[i];
			return (diferencia);
		}
		i++;
	}
	return (0);
}

static int	ft_exit_with_error(t_stacks *stacks)
{
	ft_print_error_message();
	ft_clean_stack(stacks->a);
	ft_clean_stack(stacks->b);
	exit(1);
}

static void	ft_execute_movement(char *instruction, t_stacks *stacks)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		ft_sa_implementation(stacks);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		ft_sb_implementation(stacks);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ft_ss_implementation(stacks);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		ft_pa_implementation(stacks);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		ft_pb_implementation(stacks);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ft_ra_implementation(stacks);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		ft_rb_implementation(stacks);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		ft_rr_implementation(stacks);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		ft_rra_implementation(stacks);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		ft_rrb_implementation(stacks);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		ft_rrr_implementation(stacks);
	else
		ft_exit_with_error(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*str;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	stacks.a = ft_init_stack(argc - 1, argv + 1);
	stacks.b = NULL;
	if (stacks.a)
	{
		str = get_next_line(0);
		while (str)
		{
			ft_execute_movement(str, &stacks);
			free(str);
			str = get_next_line(0);
		}
		if (ft_is_sorted(stacks.a) && !(stacks.b))
			ft_print_message("OK");
		else
			ft_print_message("KO");
		ft_clean_stack(stacks.a);
		ft_clean_stack(stacks.b);
	}
}
