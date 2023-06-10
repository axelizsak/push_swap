/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:55:34 by aizsak            #+#    #+#             */
/*   Updated: 2023/02/09 18:29:54 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_pile
{
	int				data;
	int				pos;
	struct s_pile	*next;
}					t_pile;

int					already_sorted(t_pile **pile_a);
long long int		check_atoi(const char *nptr);
t_pile				*pl_last(t_pile *pl);
void				pl_add_back(t_pile **pl, t_pile *new);
void				free_all(t_pile **pile_a, t_pile **pile_b, int *tab);
void				free_a(t_pile **pile_a, int *tab);
long long int		check_nb(int argc, char **argv);
int					check_double(int argc, char **argv);
int					check_digit(int argc, char **argv);
int					check_over(int argc, char **argv);
int					check_push(int argc, char **argv);
int					get_small(t_pile **pile_a);
void				sorting_3(t_pile **pile_a);
void				sorting_4(t_pile **pile_a, t_pile **pile_b);
void				sorting_5(t_pile **pile_a, t_pile **pile_b);
void				sorting_100(t_pile **pile_a, t_pile **pile_b, int argc);
void				sorting_500(t_pile **pile_a, t_pile **pile_b, int agrc);
int					get_pos(t_pile **pile_a, int small);
void				ra(t_pile **pile_a);
void				rb(t_pile **pile_b);
t_pile				*get_pre_last(t_pile *pile);
void				rra(t_pile **pile_a);
void				rrb(t_pile **pile_b);
void				pl_add_front(t_pile **pl, t_pile *new);
void				pa(t_pile **pile_a, t_pile **pile_b);
void				pb(t_pile **pile_a, t_pile **pile_b);
void				sa(t_pile **pile_a);
void				sb(t_pile **pile_b);
int					one_arg(char *arg);
int					too_long(char *arg);
int					ft_isdigit(int c);
void				sorting_b(t_pile **pile_a, t_pile **pile_b, int argc);
int					rb_or_rrb(t_pile **pile_b, int size);
int					len_pile_a(t_pile **pile_a);
void				sorting(t_pile **pile_a, t_pile **pile_b, int argc);

#endif
