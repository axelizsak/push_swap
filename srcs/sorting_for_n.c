/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_for_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:31:10 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/02 17:41:34 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_small(t_pile **pile_a)
{
	t_pile	*tmp;
	int		small;

	tmp = *pile_a;
	small = *pile_a->data;
	while (*pile_a != NULL)
	{
		if (small > *pile_a->data)
			small = *pile_a->data;
		*pile_a = *pile_a->next;
	}
	*pile_a = tmp;
	return (small);
}

void	sorting_3(t_pile **pile_a)
{
	int	a;
	int	b;
	int	c;

	a = *pile_a->data;
	b = *pile_a->next->data;
	c = *pile_a->next->next->data;
	if (a > b && c > b && c > a)
		sa(pile_a);
	else if (a > b && a > c && b > c)
	{
		sa(pile_a);
		rra(pile_a);
	}
	else if (a > b && c > b && a > c)
		ra(pile_a);
	else if (a < b && a < c && b > c)
	{
		sa(pile_a);
		ra(pile_a);
	}
	else if (a < b && a > c && b > c)
		rra(pile_a);
}

void	sorting_4(t_pile **pile_a, t_pile **pile_b)
{
	int	snall;

	small = get_small(pile_a);
	while (*pile_a->data != small)
		ra(pile_a);
	pb(pile_a, pile_b);
	sorting_3(pile_a);
	pa(pile_a, pile_b)
}
