/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:51:02 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/03 01:50:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static t_stk	*stk_element(char *nb)
{
	t_stk	*stk;

	stk = malloc(sizeof(t_stk));
	if (!stk)
		return (NULL);
	if (ft_atoi_secure(&(stk->n), nb))
	{
		write(2, "Error\n", 6);
		free(stk);
		return (NULL);
	}
	stk->next = NULL;
	return (stk);
}

static t_stk	*build_stk(char **lst, int ac)
{
	t_stk	*top;
	t_stk	*stk;
	t_stk	*prev;
	int		i;

	i = 1;
	stk = stk_element(lst[1]);
	if (!stk)
		return (NULL);
	top = stk;
	while (++i < ac)
	{
		prev = stk;
		stk = stk_element(lst[i]);
		prev->next = stk;
		if (!stk)
		{
			stk_free(top);
			return (NULL);
		}
		stk->prev = prev;
	}
	stk->next = top;
	top->prev = stk;
	return (top);
}

t_both	*init_stk(char **lst, int ac)
{
	t_both	*r;

	r = malloc(sizeof(t_both));
	if (!r)
		return (NULL);
	r->a = build_stk(lst, ac);
	if (!(r->a))
	{
		free(r);
		return (NULL);
	}
	r->b = NULL;
	r->a_size = ac - 1;
	r->b_size = 0;
	return (r);
}
