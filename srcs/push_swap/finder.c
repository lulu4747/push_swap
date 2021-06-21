/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:33:11 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/21 17:33:14 by lfourage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	first_scan(t_stk *t)
{
	int	ret;

	ret = t->n;
	t = t->prev;
	while (t->n == ret - 1)
	{
		ret = t->n;
		t = t->prev;
	}
	return (ret);
}

static int	top_scan(t_stk *first, int min, int max, int *ct)
{
	t_stk	*t;

	t = first->next;
	while (t != first && (t->n < min || t->n > max))
	{
		t = t->next;
		*ct = *ct + 1;
	}
	if (t == first)
		return (0);
	return (t->n);
}

static int	bot_scan(t_stk *first, int min, int max, int *cb)
{
	t_stk	*t;
	int		ret;

	t = first->prev;
	while (t != first && (t->n < min || t->n > max))
	{
		t = t->prev;
		*cb = *cb + 1;
	}
	if (t == first)
		return (0);
	ret = t->n;
	t = t->prev;
	while (t->n == ret - 1)
	{
		ret = t->n;
		t = t->prev;
	}
	return (ret);
}

int	fnd(t_stk *first, int min, int max)
{
	int	top;
	int	bot;
	int	ct;
	int	cb;

	if (first->n >= min && first->n <= max)
		return (first_scan(first));
	ct = 1;
	cb = 0;
	top = top_scan(first, min, max, &ct);
	bot = bot_scan(first, min, max, &cb);
	if (ct <= cb)
		return (top);
	return (bot);
}
