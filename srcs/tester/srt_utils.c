/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:50:58 by lfourage          #+#    #+#             */
/*   Updated: 2021/05/31 12:51:00 by lfourage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

t_stk	*stk_last(t_stk *stk)
{
	t_stk	*last;

	last = stk;
	while (last->next != stk)
		last = last->next;
	return (last);
}

static int	*stk_cpy_srt(t_stk *stk, int size)
{
	int	i;
	int	*t;

	t = malloc(sizeof(int) * size);
	if (!t)
	{
		stk_free(stk);
		return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		t[i] = stk->n;
		stk = stk->next;
	}
	t = ft_sort(t, size);
	return (t);
}

t_stk	*reform(t_stk *a, int size)
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

int	get_ins(char *ins, t_both **t)
{
	if (ins == NULL)
		return (0);
	else if (!ft_strcmp(ins, "sa"))
		return (swap_read(SA, t));
	else if (!ft_strcmp(ins, "sb"))
		return (swap_read(SB, t));
	else if (!ft_strcmp(ins, "ss"))
		return (swap_read(SS, t));
	else if (!ft_strcmp(ins, "ra"))
		return (rotate_read(RA, t));
	else if (!ft_strcmp(ins, "rb"))
		return (rotate_read(RB, t));
	else if (!ft_strcmp(ins, "rr"))
		return (rotate_read(RR, t));
	else if (!ft_strcmp(ins, "pa"))
		return (push_read(PA, t));
	else if (!ft_strcmp(ins, "pb"))
		return (push_read(PB, t));
	else if (!ft_strcmp(ins, "rra"))
		return (rotate_read(RRA, t));
	else if (!ft_strcmp(ins, "rrb"))
		return (rotate_read(RRB, t));
	else if (!ft_strcmp(ins, "rrr"))
		return (rotate_read(RRR, t));
	return (write(2, "Error\n", 6));
}
