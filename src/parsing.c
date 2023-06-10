/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:27:38 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/09 13:39:41 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	check_nb(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= -2147483648)
			return (0);
		if (ft_atoi(argv[i]) > 2147483647)
			return (0);
		if ((argv[i][0] == '+' || argv[i][0] == '-') && (argv[i][1]
					< '0' || argv[i][1] > '9'))
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

int	check_digit(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = 0;
		k = ft_strlen1(argv[i]);
		while (j < k)
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != 32)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_over(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!too_long(argv[i]))
			return (0);
		if (!one_arg(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_push(int argc, char **argv)
{
	if (!check_nb(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!check_over(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!check_double(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!check_digit(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
