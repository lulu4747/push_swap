#include "ps.h"

static int	nb_cmp(char *s1, char *s2)
{
	if (!ft_strcmp(s1, s2))
	{
		write(2, "Error\n2 or more occurences of the", 32);
		write(2, " same number\nClosing program\n", 29);
		return (1);
	}
	if (ft_is_number(s1) != 0)
	{
		write(2, "Error\nNon-numerical value found\n", 32);
		write(2, "Closing program\n", 16);
		return (1);
	}
	return (0);
}

static int	ft_dup_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = ac - 1;
	if (ft_is_number(av[j]) != 0)
	{
		write(2, "Error\nNon-numerical value found\n", 32);
		write(2, "Closing program\n", 16);
		return (1);
	}
	while (i < j)
	{
		j = i + 1;
		while (j < ac)
		{
			if (nb_cmp(av[i], av[j]) != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int sorted(int ac, char **av)
{
	int i;
	int na;
	int nb;

	i = 2;
	if (ft_atoi_secure(&na, av[1]) == -1)
	{
		write(2, "Error\nOverflow\nClosing program\n", 32);
		return (1);
	}
	while (i < ac)
	{
		if (ft_atoi_secure(&nb, av[i]) == -1)
		{
		write(2, "Error\nOverflow\nClosing program\n", 32);
			return (1);
		}
		if (na >= nb)
			return (1);
		na = nb;
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_both	*t;
	int	ret;

 	if (ac < 3)
		return (1);
	ret = sorted(ac, av);
	if (ret != 1)
		return (ret);
	t = NULL;
	if (!ft_dup_check(ac, av))
		t = init_stk(av, ac);
	if (!t)
		return (1);
	if (solver(t) != 1)
		return (1);
	both_free(t);
	return (0);
}