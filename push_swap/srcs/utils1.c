/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:41:11 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/08 16:08:03 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb_or_rrb(t_pile **pile_b, int size)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = *pile_b;
	while (tmp)
	{
		if (tmp->pos == size)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	sorting_b(t_pile **pile_a, t_pile **pile_b, int argc)
{
	int	size;
	int	half;
	int	location;

	size = argc - 2;
	location = 0;
	half = 0;
	while (*pile_b != NULL)
	{
		half = (size + 1) / 2;
		location = rb_or_rrb(pile_b, size);
		if ((*pile_b)->pos == size)
		{
			pa(pile_a, pile_b);
			size--;
		}
		else if (location <= half && (*pile_b)->pos != size)
			rb(pile_b);
		else if (location > half && (*pile_b)->pos != size)
			rrb(pile_b);
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	too_long(char *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]))
			j++;
		i++;
	}
	if (j > 11)
		return (0);
	return (1);
}

int	one_arg(char *arg)
{
	int	i;
	
	i = 0;
	while (arg[i] == 32)
		i++;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (ft_isdigit(arg[i]))
		i++;
	while (arg[i] == 32)
		i++;
	if (arg[i] != '\0')
		return (0);
	return (1);
}
