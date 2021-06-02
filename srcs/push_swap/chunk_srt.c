/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_srt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:48:28 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/02 21:16:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	fnd(t_stk *first, t_stk *t, int cs, int max)
{
	int		n[4];

	if (first->n >= cs && first->n <= max)
		return (first->n);
	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	n[3] = 1;
	while (t != first)
	{
		if (t->n >= cs && t->n <= max)
		{
			if (n[0] == 0)
				n[0] = t->n;
			n[1] = t->n;
			n[2] = 0;
		}
		if (n[0] == 0)
			(n[3])++;
		(n[2])++;
		t = t->next;
	}
	if (n[3] <= n[2] || n[2] - n[3] - cs < n[1] - n[0])
		return (n[0]);
	return (n[1]);
}

static int	fnd_sub(t_stk *first, int n)
{
	t_stk	*stk;
	int		ret;

	stk = first->next;
	ret = first->n;
	while (stk != first)
	{
		if (stk->n > ret && stk->n < n)
			ret = stk->n;
		stk = stk->next;
	}
	return (ret);
}

static int	chunk(t_both *t, int c, int s)
{
	int	i;

	i = 0;
	while (i < s)
	{
		get_on_top(t, &(t->a), fnd(t->a, t->a->next, c, (c + (s - 1))), RA);
		if (t->b_size > 1)
			get_on_top(t, &(t->b), fnd_sub(t->b, t->a->n), RB);
		cmd_send(PB, 0, &t);
		i++;
	}
	return (s);
}

static int tweak_size(int n)
{
	if (n > 400)
		return (n * 0.09);
	if (n > 300)
		return (n * 0.10);
	if (n > 200)
		return (n * 0.12);
	if (n > 100)
		return (n * 0.15);
	if (n > 70)
		return (n * 0.20);
	if (n > 45)
		return (n * 0.22);
	if (n > 17)
		return (n * 0.27);
	return (n);
}

int	chunk_srt(t_both *t)
{
	int	cs;
	int	size;

	cs = 1;
	while (t->a_size > 0)
	{
		size = tweak_size(t->a_size);
		cs += chunk(t, cs, size);
	}
	while (t->b_size > 0)
	{
		get_on_top(t, &(t->b), t->b_size, RB);
		if (cmd_send(PA, 0, &t) != 0)
			return (1);
	}
	return (0);
}
