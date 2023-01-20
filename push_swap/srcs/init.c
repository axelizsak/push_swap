#include "push_swap.h"

t_pile	*new_pile(int data)
{
	t_pile	*new_data;

	new_data = malloc(sizeof * new_data);
	if (!new_data)
		return (NULL);
	new_data->data = data;
	new_data->index = 0;
	new_data->pos = -1;
	new_data->target_pos = -1;
	new_data->cost_a = -1;
	new_data->cost_b = -1;
	new_data->next = NULL;
	return (new_data);
}

t_pile	*get_pile_down(t_pile *pile)
{
	while (pile && pile->next != NULL)
		pile = pile->next;
	return (pile);
}

void	pile_down(t_pile **pile, t_pile *new)
{
	t_pile	*end;

	if (!new)
		return (0);
	if (!*pile)
	{
		*pile = new;
		return (0);
	}
	end = get_pile_down(*pile);
	end->next = new;
}

t_pile *pile_data(int argc, char **argv)
{
	t_pile		*pile_a;
	int		nb;
	int		i;

	pile_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (0);
		if (i == 1)
			pile_a = new_pile((int)nb);
		else
			pile_down(&pile_a, new_pile((int)nb));
		i++;
	}
	return (pile_a);
}
