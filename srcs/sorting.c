/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:42:07 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/02 17:41:47 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_pile **pile_a)
{
	t_pile *tmp;

	tmp = *pile_a;
	while (*pile_a->next != NULL)
	{
		if (*pile_a->data > *pile_a->next->data)
		{
			*pile_a = tmp;
			return (0);
		}
		*pile_a = *pile_a->next;
	}
	*pile_a = tmp;
	return (1);
}

int	len_pile_a(t_pile **pile_a)
{
	int	len;
	t_pile	*tmp;

	len = 1;
	tmp = *pile_a;
	while (*pile_a->next != NULL)
	{
		len++;
		*pile_a = *pile_a->next;
	}
	*pile_a = tmp;
	return (len);
}

void	sorting(t_pile **pile_a, t_pile **pile_b, int argc)
{
	int	len;

	len = len_pile_a(pile_a);
}
