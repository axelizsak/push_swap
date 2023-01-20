/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:55:34 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/11 13:45:55 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H

# include "libft.h"

typedef	struct s_pile
{
	int		data;
	int		index;
	int		pos;
	int		target_pos;
	int		cost_a;
	int		cost_b;
	struct	s_pile *next;
}	t_pile


t_pile	*pile_data(int argc, char **argv);
t_pile	*new_pile(int data);
t_pile	*get_pile_down(t_pile *pile);
void	pile_down(t_pile **pile, t_pile *new);
void	indexing(t_pile *pile_a, int pile_size);
int	ft_nbstrcmp(const char *s1, const char *s2);
static int	check_nb(char *argv);
static int	check_multi(char **argv);
static int	check_zero(char *argv);
int		check_argv(char **argv);
int		get_pile_size(t_pile *pile);
int		check_digit(char c);
int		check_sign(char c);
#endif
