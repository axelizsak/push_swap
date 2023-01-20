#include "push_swap.h"

int	ft_nbstrcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

static int	check_nb(char *argv)
{
	int	i;

	i = 0;
	if (check_sign(argv[i]) && argv[i + 1])
		i++;
	while (argv[i] && check_digit(argv[i]))
		i++;
	if (argv[i] && !check_digit(argv[i]))
		return (0);
	return (1);
}

static int	check_multi(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (i != j && ft_nbstrcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_zero(char *argv)
{
	int	i;

	i = 0;
	if (check_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == 0)
		i++;
	if (argv[i])
		return (0);
	return (1);
}

int	check_argv(char **argv)
{
	int	i;
	int	nb;
	
	i = 1;
	nb = 0;
	while (argv[i])
	{
		if (!check_nb(argv[i]))
			return (0);
		nb += check_zero(argv[i]);
		i++;
	}
	if (nb > 1)
		return (0);
	if (check_multi(argv))
		return (0);
	return (1);
}
