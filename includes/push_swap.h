/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:55:34 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/02 12:59:29 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H

# include "libft.h"

typedef	struct s_pile
{
	int	data;
	int	pos;
	struct s_pile	*next;
}	t_pile;

int		already_sorted(t_pile **pile_a);
long long int	check_atoi(const char *nptr);
t_pile	*pl_last(t_pile *pl);
void	*pl_add_back(t_pile **pl, t_pile *new);
void	free_all(t_pile **pile_a, t_pile **pile_b, int *tab);
void	free_a(t_pile **pile_a, int *tab);
long long int	check_nb(int argc, char **argv);
int		check_double(int argc, char **argv);
int		check(int argc, char **argv);
#endif
