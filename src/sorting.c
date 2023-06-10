/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:42:07 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/08 16:09:37 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_pile **pile_a)
{
	t_pile	*tmp;

	tmp = *pile_a;
	while ((*pile_a)->next != NULL)
	{
		if ((*pile_a)->data > (*pile_a)->next->data)
		{
			*pile_a = tmp;
			return (0);
		}
		*pile_a = (*pile_a)->next;
	}
	*pile_a = tmp;
	return (1);
}

int	len_pile_a(t_pile **pile_a)
{
	int		len;
	t_pile	*tmp;

	len = 1;
	tmp = *pile_a;
	while ((*pile_a)->next != NULL)
	{
		len++;
		*pile_a = (*pile_a)->next;
	}
	*pile_a = tmp;
	return (len);
}

void	sorting(t_pile **pile_a, t_pile **pile_b, int argc)
{
	int	len;

	len = len_pile_a(pile_a);
	if (len == 2)
		sa(pile_a);
	else if (len == 3)
		sorting_3(pile_a);
	else if (len == 4)
		sorting_4(pile_a, pile_b);
	else if (len == 5)
		sorting_5(pile_a, pile_b);
	else if (len > 5 && len <= 100)
		sorting_100(pile_a, pile_b, argc);
	else
		sorting_500(pile_a, pile_b, argc);
}

int	get_small(t_pile **pile_a)
{
	t_pile	*tmp;
	int		small;

	tmp = *pile_a;
	small = (*pile_a)->data;
	while (*pile_a != NULL)
	{
		if (small > (*pile_a)->data)
			small = (*pile_a)->data;
		*pile_a = (*pile_a)->next;
	}
	*pile_a = tmp;
	return (small);
}

int	get_pos(t_pile **pile_a, int small)
{
	t_pile	*tmp;
	int		pos;

	tmp = *pile_a;
	pos = 0;
	while ((*pile_a)->data != small)
	{
		pos++;
		*pile_a = (*pile_a)->next;
	}
	*pile_a = tmp;
	return (pos);
}
