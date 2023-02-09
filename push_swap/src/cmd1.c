/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:42:52 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/09 18:19:05 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pile **pile_a)
{
	t_pile	*first;
	t_pile	*tmp;

	first = *pile_a;
	tmp = *pile_a;
	*pile_a = (*pile_a)->next;
	while (first->next)
		first = first->next;
	first->next = tmp;
	first->next->next = NULL;
	write (1, "ra\n", 3);
}

void	rb(t_pile **pile_b)
{
	t_pile	*last;
	t_pile	*tmp;

	last = *pile_b;
	tmp = *pile_b;
	*pile_b = (*pile_b)->next;
	if (*pile_b == NULL)
		return ;
	while (last->next)
		last = last->next;
	last->next = tmp;
	last->next->next = NULL;
	write (1, "rb\n", 3);
}

t_pile	*get_pre_last(t_pile *pile)
{
	t_pile	*pre_last;

	pre_last = NULL;
	if (pile && pile->next)
	{
		pre_last = pile;
		while (pre_last->next->next)
			pre_last = pre_last->next;
	}
	return (pre_last);
}

void	rra(t_pile **pile_a)
{
	t_pile	*pre_last;
	t_pile	*last;
	t_pile	*tmp;

	if (*pile_a && (*pile_a)->next)
	{
		tmp = *pile_a;
		pre_last = get_pre_last(*pile_a);
		last = pre_last->next;
		pre_last->next = NULL;
		last->next = tmp;
		*pile_a = last;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_pile **pile_b)
{
	t_pile	*pre_last;
	t_pile	*last;
	t_pile	*tmp;

	if (*pile_b && (*pile_b)->next)
	{
		tmp = *pile_b;
		pre_last = get_pre_last(*pile_b);
		last = pre_last->next;
		pre_last->next = NULL;
		last->next = tmp;
		*pile_b = last;
		write(1, "rrb\n", 4);
	}
}
