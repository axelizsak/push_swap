/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:15:53 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/02 12:51:39 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	check_atoi(const char *nptr)
{
	long long int	n;

	n = ft_atoi(nptr);
	if (n < -2147483648 || n > 2147483647)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (n);
}

t_pile	*pl_last(t_pile *pl)
{
	while (pl != NULL)
	{
		if (pl->next = NULL)
			return (pl);
		pl = pl->next;
	}
	return (pl);
}

void	*pl_add_back(t_pile **pl, t_pile *new)
{
	i f(!*pl)
		*pl = new;
	else
		pl_last(*pl)->next = new;
}

void	free_all(t_pile **pile_a, t_pile **pile_b, int *tab)
{
	t_pile	*tmp;

	while (*pile_a != NULL)
	{
		tmp = *pile_a->next;
		free(*pile_a);
		*pile_a = tmp;
	}
	while (*pile_b != NULL)
	{
		tmp = *pile_b->next;
		free(*pile_b);
		*pile_b = tmp;
	}
	free(tab);
}

void	free_a(t_pile **pile_a, int *tab)
{
	t_pile	tmp;

	while (*pile_a != NULL)
	{
		tmp = *pile_a->next;
		free(*pile_a);
		*pile_a = tmp;
	}
	free(tab);
}
