/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <lfourage@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:50:13 by lfourage          #+#    #+#             */
/*   Updated: 2021/05/31 18:40:36 by lfourage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int	cmpn(t_stk *stk)
{
	int	n1;
	int	n2;

	n1 = stk->n;
	n2 = stk->next->n;
	if (n1 > n2)
	{
		write(2, "KO\n", 3);
		return (1);
	}
	return (0);
}

int	is_sorted(t_both **t, int ret)
{
	t_stk	*stk;

	if ((*t)->b_size != 0 && !ret)
	{
		write(2, "KO\n", 3);
		ret = 1;
	}
	stk = (*t)->a;
	stk = stk->next;
	if ((*t)->a->n > stk->n && !ret)
	{
		write(2, "KO\n", 3);
		ret = 1;
	}
	while (stk->next != (*t)->a && !ret)
	{
		ret = cmpn(stk);
		stk = stk->next;
	}
	if (!ret)
		write(1, "OK\n", 3);
	both_free(*t);
	return (0);
}
