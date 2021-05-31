/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:50:47 by lfourage          #+#    #+#             */
/*   Updated: 2021/05/31 12:50:50 by lfourage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int	nb_cmp(char *s1, char *s2)
{
	if (!ft_strcmp(s1, s2))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_is_number(s1) != 0)
	{
		write(2, "Error\n", 6);
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
		write(2, "Error\n", 6);
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

static int	no_need(int ac, char **av)
{
	int	ret;

	ret = 0;
	if (ac == 2)
	{
		ret = ft_dup_check(ac, av);
		if (!ret)
			write(1, "OK\n", 3);
	}
	return (ret);
}

int	main(int ac, char **av)
{
	t_both	*t;
	int		ret;
	char	*line;

	if (ac < 3)
		return (no_need(ac, av));
	t = NULL;
	if (!ft_dup_check(ac, av))
		t = init_stk(av, ac);
	if (!t)
		return (1);
	t->a = reform(t->a, t->a_size);
	if (!(t->a))
		return (1);
	ret = 1;
	line = NULL;
	while (ret)
	{
		ret = get_next_line(&line, &ret);
		get_ins(line, &t);
		free(line);
		line = NULL;
	}
	return (is_sorted(t));
}
