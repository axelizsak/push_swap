#include "push_swap.h"

int	get_pile_size(t_pile *pile)
{
	int	size;

	size = 0;
	if (!pile)
		return (0);
	while (pile)
	{
		pile = pile->next;
		size++;
	}
	return (size);
}

int	check_digit(char c)
{
	return (c >= '0' && c <= '9')
}

int	check_sign(char c)
{
	return (c == '+' || c == '-')
}

void	indexing(t_pile *pile_a, int pile_size)
{
	t_pile *ptr;
	t_pile *max;
	int		data;

	while (--pile_size > 0)
	{
		ptr = stack_a;
		data = -2147483648;
		max = NULL;
		while (ptr)
		{
			if (ptr->data == -2147483648 && ptr->index == 0)
				ptr->index = 1;
			if (ptr->data > data && ptr->index == 0)
			{
				data = ptr->data;
				max = ptr;
				ptr = pile_a;
			}
			else
				ptr = ptr->next;
		}
		if (max != NULL)
			max->index = pile_size;
	}
}
