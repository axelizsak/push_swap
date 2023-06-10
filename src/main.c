/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:40:40 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/08 16:04:41 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*init_nb(int a, int b, t_pile **pile_a, int *tab)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
	{
		free_a(pile_a, tab);
		return (NULL);
	}
	new->data = a;
	new->pos = b;
	new->next = NULL;
	return (new);
}

void	init_pile(t_pile **pile_a, int argc, char **argv, int *tab)
{
	int		i;
	int		j;
	t_pile	*tmp;

	i = 1;
	j = 0;
	while (i < argc)
	{
		tab[j] = check_atoi(argv[i]);
		tmp = init_nb(ft_atoi(argv[i]), j, pile_a, tab);
		pl_add_back(pile_a, tmp);
		i++;
		j++;
	}
}

void	sorting_tab(int *tab, int argc)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < argc - 2)
	{
		j = 0;
		while (j < argc - 2 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	add_pos(t_pile **pile_a, int *tab, int argc)
{
	int		i;
	t_pile	*tmp;

	tmp = *pile_a;
	while (tmp != NULL)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (tmp->data == tab[i])
				tmp->pos = i;
			i++;
		}
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		*tab;

	if (argc == 1)
		return (0);
	pile_a = NULL;
	pile_b = NULL;
	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab)
		return (0);
	if (!check_push(argc, argv))
	{
		free_all(&pile_a, &pile_b, tab);
		return (0);
	}
	init_pile(&pile_a, argc, argv, tab);
	if (already_sorted(&pile_a))
		return (0);
	sorting_tab(tab, argc);
	add_pos(&pile_a, tab, argc);
	if (!already_sorted(&pile_a))
		sorting(&pile_a, &pile_b, argc);
	free_all(&pile_a, &pile_b, tab);
}
