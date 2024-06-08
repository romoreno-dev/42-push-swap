/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:10:18 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/10 11:10:18 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	ft_are_all_numbers(char **numbers);
static int	ft_is_valid_number(char **numbers);

int	ft_check_input(char **numbers)
{
	return (ft_are_all_numbers(numbers) && ft_is_valid_number(numbers));
}

static int	ft_are_all_numbers(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	if (!numbers)
		return (0);
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			if (ft_isdigit(numbers[i][j]) == 0 && numbers[i][j] != '+'
			&& numbers[i][j] != '-')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_is_valid_number(char **numbers)
{
	long	number;
	int		i;
	int		quantity;
	long	*number_list;

	i = 0;
	quantity = ft_quantity(numbers);
	number_list = (long *)malloc(sizeof(long *) * quantity);
	if (!number_list)
		return (0);
	while (numbers[i])
	{
		number = ft_atol(numbers[i]);
		if (ft_integer_overflow(number)
			|| ft_is_repeated(number, number_list, i))
		{
			free(number_list);
			return (0);
		}
		number_list[i] = number;
		i++;
	}
	free(number_list);
	return (1);
}
