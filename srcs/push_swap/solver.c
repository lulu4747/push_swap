/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <lfourage@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:49:17 by lfourage          #+#    #+#             */
/*   Updated: 2021/05/31 16:59:00 by lfourage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static t_both	*three_srt(t_both *t)
{
	if (t->a->n < t->a->next->n)
	{
		if (t->a->n < t->a->next->next->n)
			cmd_print("sa", "ra", &t);
		else
			cmd_print("rra", NULL, &t);
	}
	else
	{
		if (t->a->n < t->a->next->next->n)
			cmd_print("sa", NULL, &t);
		else if (t->a->next->n < t->a->next->next->n)
			cmd_print("ra", NULL, &t);
		else
			cmd_print("sa", "rra", &t);
	}
	return (t);
}

static int	quick(t_both **t)
{
	while ((*t)->a_size > 3 && sorted(*t) == 1)
	{
		get_on_top(*t, &((*t)->a), stk_min((*t)->a), 'a');
		cmd_print("pb", NULL, t);
	}
	if (sorted(*t) == 1)
		*t = three_srt(*t);
	while ((*t)->b_size > 0)
		cmd_print("pa", NULL, t);
	return (0);
}

static int	simple(t_both **t)
{
	while ((*t)->a_size > 0)
	{
		get_on_top(*t, &((*t)->a), stk_min((*t)->a), 'a');
		cmd_print("pb", NULL, t);
	}
	while ((*t)->b_size > 0)
		cmd_print("pa", NULL, t);
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
	if ((*t)->a_size <= 100)
		return (chunk_srt(*t, ((*t)->a_size / 17), 17));
	return (chunk_srt(*t, ((*t)->a_size / 45), 45));
}
