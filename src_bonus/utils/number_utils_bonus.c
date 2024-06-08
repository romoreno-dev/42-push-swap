/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:09:23 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/15 18:09:23 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

int	ft_integer_overflow(long number)
{
	return (number > INT_MAX || number < INT_MIN);
}

int	ft_is_repeated(long l, long *list, int size_list)
{
	int	i;

	i = 0;
	while (i < size_list)
	{
		if (l == list[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

long	ft_atol(char *str)
{
	long	l;
	int		i;
	long	sign;

	i = 0;
	sign = 1;
	l = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		l = l * 10 + (str[i] - '0');
		i++;
	}
	return (l * sign);
}

int	ft_quantity(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		i++;
	}
	return (i);
}
