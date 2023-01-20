/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:54:44 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/10 12:55:06 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_pile *pile)
{
	while (t_pile *pile)
	{
		if (pile->data > pile->next->data)
			return (0);
		pile = pile->next;
	}
	return (1);
}

//push_swap

int	main(int argc, char **argv)
{
	t_pile *pile_a;
	t_pile *pile_b;
	int	pile_size;

	if (argc < 2)
		return (0);
	if (!check_argv(argv))
		return (0);
	pile_a = pile_data(agrc, argv);
	pile_b = NULL;
	pile_size = get_pile_size(pile_a);
	indexing(pile_a, pile_size + 1);
	//pushswap
	//free(pile_a)
	//free(pile_b)
	return (0);
}
