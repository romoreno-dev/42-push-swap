/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:26:50 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/16 12:26:50 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*ft_init_stack(int array_size, char **input_array)
{
	t_stack	*a;
	char	**numbers;

	a = NULL;
	if (array_size == 1)
	{
		numbers = ft_split(input_array[0], ' ');
	}
	else
		numbers = input_array;
	if (ft_check_input(numbers))
	{
		a = ft_fill_stack(numbers);
	}
	else
		ft_print_error_message();
	if (array_size == 1)
	{
		ft_clean_array(numbers);
	}
	return (a);
}

t_stack	*ft_fill_stack(char **numbers)
{
	t_stack	*start_node;
	t_stack	*current_node;

	start_node = NULL;
	current_node = NULL;
	while (*numbers)
	{
		if (!start_node)
		{
			start_node = ft_new_node(ft_atoi(*numbers));
			current_node = start_node;
		}
		else
		{
			current_node->next = ft_new_node(ft_atoi(*numbers));
			current_node = current_node->next;
		}
		numbers++;
	}
	return (start_node);
}

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->value = value;
	node->position = -1;
	node->target_element = NULL;
	node->cost = -1;
	node->cheapest = -1;
	return (node);
}
