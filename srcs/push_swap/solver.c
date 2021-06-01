/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:49:17 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/01 18:32:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static t_both	*three_srt(t_both *t)
{
	if (t->a->n < t->a->next->n)
	{
		if (t->a->n < t->a->next->next->n)
			cmd_send(SA, RA, &t);
		else
			cmd_send(RRA, 0, &t);
	}
	else
	{
		if (t->a->n < t->a->next->next->n)
			cmd_send(SA, 0, &t);
		else if (t->a->next->n < t->a->next->next->n)
			cmd_send(RA, 0, &t);
		else
			cmd_send(SA, RRA, &t);
	}
	return (t);
}

static int	quick(t_both **t)
{
	while ((*t)->a_size > 3 && sorted(*t) == 1)
	{
		get_on_top(*t, &((*t)->a), stk_min((*t)->a), RA);
		cmd_send(PB, 0, t);
	}
	if (sorted(*t) == 1)
		*t = three_srt(*t);
	while ((*t)->b_size > 0)
		cmd_send(PA, 0, t);
	return (0);
}

static int	simple(t_both **t)
{
	while ((*t)->a_size > 0)
	{
		get_on_top(*t, &((*t)->a), stk_min((*t)->a), RA);
		cmd_send(PB, 0, t);
	}
	while ((*t)->b_size > 0)
		cmd_send(PA, 0, t);
	return (0);
}

static t_stk	*reform(t_stk *a, int size)
{
	int		i;
	int		*t;
	t_stk	*first;

	first = a;
	t = stk_cpy_srt(a, size);
	if (!t)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (a->n != t[i])
			a = a->next;
		a->n = i + 1;
		a = a->next;
	}
	free(t);
	a = first;
	return (a);
}

int	solver(t_both **t)
{
	(*t)->a = reform((*t)->a, (*t)->a_size);
	if (!(*t)->a)
		return (-1);
	if ((*t)->a_size <= 5)
		return (quick(t));
	else if ((*t)->a_size <= 17)
		return (simple(t));
	return (chunk_srt(*t));
}
