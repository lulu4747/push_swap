/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:48:34 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/02 23:39:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int ac, char **av)
{
	t_both	*t;
	int		ret;

	if (ac == 1)
		return (0);
	if (ac == 2)
		return (ft_dup_check(ac, av));
	t = NULL;
	if (!ft_dup_check(ac, av))
		t = init_stk(av, ac);
	if (!t)
		return (1);
	while (sorted(t) != 0)
	{
		ret = solver(&t);
		if (ret != 0)
			return (1);
	}
	both_free(t, 0);
	return (0);
}
