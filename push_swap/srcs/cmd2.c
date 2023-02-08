/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:16:55 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/08 13:57:09 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pl_add_front(t_pile **pl, t_pile *new)
{
	if (!pl)
		return ;
	new->next = *pl;
	*pl = new;
}

void	pa(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	if (*pile_b)
	{
		tmp = (*pile_b)->next;
		(*pile_b)->next = *pile_a;
		*pile_a = *pile_b;
		*pile_b = tmp;
		write(1, "pa\n", 3);
	}
}

void	pb(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	if (*pile_a)
	{
		tmp = (*pile_a)->next;
		(*pile_a)->next = *pile_b;
		*pile_b = *pile_a;
		*pile_a = tmp;
		write (1, "pb\n", 3);
	}
}

void	sa(t_pile **pile_a)
{
	int	tmp;

	if (!*pile_a)
		return ;
	tmp = (*pile_a)->data;
	(*pile_a)->data = (*pile_a)->next->data;
	(*pile_a)->next->data = tmp;
	tmp = (*pile_a)->pos;
	(*pile_a)->pos = (*pile_a)->next->pos;
	(*pile_a)->next->pos = tmp;
	write (1, "sa\n", 1);
}

void	sb(t_pile **pile_b)
{
	int	tmp;

	if (!*pile_b)
		return ;
	tmp = (*pile_b)->data;
	(*pile_b)->data = (*pile_b)->next->data;
	(*pile_b)->next->data = tmp;
	tmp = (*pile_b)->pos;
	(*pile_b)->pos = (*pile_b)->next->pos;
	(*pile_b)->next->pos = tmp;
	write(1, "sb\n", 3);
}
