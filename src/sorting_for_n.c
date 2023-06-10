/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_for_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:31:10 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/08 16:01:52 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_3(t_pile **pile_a)
{
	int	a;
	int	b;
	int	c;

	a = (*pile_a)->data;
	b = (*pile_a)->next->data;
	c = (*pile_a)->next->next->data;
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
	int	small;

	small = get_small(pile_a);
	while ((*pile_a)->data != small)
		ra(pile_a);
	pb(pile_a, pile_b);
	sorting_3(pile_a);
	pa(pile_a, pile_b);
}

void	sorting_5(t_pile **pile_a, t_pile **pile_b)
{
	int	small;
	int	small1;
	int	half;
	int	pos;

	half = (len_pile_a(pile_a) / 2);
	small = get_small(pile_a);
	pos = get_pos(pile_a, small);
	while ((*pile_a)->data != small)
	{
		if (pos >= half)
			rra(pile_a);
		else
			ra(pile_a);
	}
	pb(pile_a, pile_b);
	small1 = get_small(pile_a);
	while ((*pile_a)->data != small1)
		ra(pile_a);
	pb(pile_a, pile_b);
	sorting_3(pile_a);
	pa(pile_a, pile_b);
	pa(pile_a, pile_b);
}

void	sorting_100(t_pile **pile_a, t_pile **pile_b, int argc)
{
	int	i;

	i = 0;
	while (*pile_a)
	{
		if ((*pile_a)->pos <= i && i > 1)
		{
			pb(pile_a, pile_b);
			rb(pile_b);
			i++;
		}
		else if ((*pile_a)->pos <= (i + 15))
		{
			pb(pile_a, pile_b);
			i++;
		}
		else if ((*pile_a)->pos >= i)
			ra(pile_a);
	}
	sorting_b(pile_a, pile_b, argc);
}

void	sorting_500(t_pile **pile_a, t_pile **pile_b, int argc)
{
	int	i;

	i = 0;
	while (*pile_a)
	{
		if ((*pile_a)->pos <= i && i > 1)
		{
			pb(pile_a, pile_b);
			rb(pile_b);
			i++;
		}
		else if ((*pile_a)->pos <= (i + 25))
		{
			pb(pile_a, pile_b);
			i++;
		}
		else if ((*pile_a)->pos >= i)
			ra(pile_a);
	}
	sorting_b(pile_a, pile_b, argc);
}
