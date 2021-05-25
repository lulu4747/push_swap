#include "ps.h"

static void visual(t_both *t)
{
	int n;
	t_stk	*a;
	t_stk	*b;

	a = t->a;
	b = t->b;
	if (t->a_size > t->b_size)
		n = t->a_size;
	else
		n = t->b_size;
	printf("	A		B\n\n");
	while (n > 0)
	{
		if (t->a_size >= n)
		{
			printf("	%d", a->n);
			a = a->next;
		}
		else
			printf("	");
		if (t->b_size >= n)
		{
			printf("		%d", b->n);
			b = b->next;
		}
		printf("\n");
		n--;
	}
	printf("_____________________________________\n");
}

static int	nb_cmp(char *s1, char *s2)
{
	if (!ft_strcmp(s1, s2))
	{
		write(2, "2 or more occurences of the", 27);
		write(2, " same number\nClosing program\n", 28);
		return (1);
	}
	if (ft_is_number(s1) != 0)
	{
		write(2, "Non-numerical value found\n", 26);
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
		write(2, "Non-numerical value found\n", 26);
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

static int sorted(char **av)
{
	int i;
	int na;
	int nb;

	i = 2;
	if (ft_atoi_secure(&na, av[1] == -1);
	{
		write(2, "Error\nn > INT_MAX or n < INT_MIN\n", 35);
		return (-1);
	}
	while (i < ac)
	{
		if (ft_atoi_secure(&nb, av[i] == -1);
		{
			write(2, "Error\nn > INT_MAX or n < INT_MIN\n", 35);
			return (-1);
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
	char	*line;
	int	ret;

 	if (ac < 3)
		return (-1)
	ret = sorted(av);
	if (ret != 1)
		return (ret);
	t = NULL;
	if (!ft_dup_check(ac, av))
		t = init_stk(av, ac);
	if (!t)
		return (-1);
	if (solver(t) !=0)
		return (-1);
	visual(t);
	while (ret)
	{
		ret = get_next_line(0, &line);
		get_ins(line, &t);
		visual(t);
		free(line);
	}
	both_free(t);
	return (0);
}