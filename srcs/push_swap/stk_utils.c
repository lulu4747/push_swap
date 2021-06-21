/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:49:49 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/03 00:52:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	stk_min(t_stk *stk)
{
	t_stk	*mv;
	int		min;

	min = stk->n;
	mv = stk->next;
	while (mv != stk)
	{
		if (mv->n < min)
			min = mv->n;
		mv = mv->next;
	}
	return (min);
}

int	stk_get(t_stk *stk, int n)
{
	int	i;

	i = 1;
	while (stk->n != n)
	{
		stk = stk->next;
		i++;
	}
	return (i);
}

t_stk	*stk_get_to(t_stk *stk, int n)
{
	while (--n > 0)
		stk = stk->next;
	return (stk);
}

t_stk	*stk_last(t_stk *stk)
{
	t_stk	*last;

	last = stk;
	while (last->next != stk)
		last = last->next;
	return (last);
}

void	get_on_top(t_both *t, t_stk **stk, int n, int cmd)
{
	int	pos;
	int	size;

	if (n == 0)
		return ;
	if (cmd == RA)
		size = t->a_size;
	else
		size = t->b_size;
	pos = stk_get((*stk), n);
	if ((pos > size / 2 && !(size % 2)) || pos > ((size / 2) + 1))
	{
		cmd += 5;
		while ((*stk)->n != n)
			cmd_send(cmd, 0, &t);
	}
	else
	{
		while ((*stk)->n != n)
			cmd_send(cmd, 0, &t);
	}
}
