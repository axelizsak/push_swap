/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:27:38 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/02 12:50:26 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	check_nb(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < -2147483648)
			return (0);
		if (ft_atoi(argv[i]) > 2147483647)
			return (0);
		if ((argv[i][0] == '+' || argv[i][0] == '-') 
				&& (argv[i][1] < '0' || argv[i][1] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_double(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		if (argv[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	check(int argc, char **argv)
{
	if (!check_nb(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!check_double(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
