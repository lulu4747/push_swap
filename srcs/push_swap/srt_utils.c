/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:49:26 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/01 18:30:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	*stk_cpy_srt(t_stk *stk, int size)
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

int	cmd_get(int cmd, t_both **t)
{
	if (cmd >= SA && cmd <= SS)
		return (swap_read(cmd, t));
	else if (cmd == PA || cmd == PB)
		return (push_read(cmd, t));
	else if (cmd >= RA && cmd <= RRR)
		return (rotate_read(cmd, t));
	return (0);
}

int	sorted(t_both *t)
{
	t_stk	*stk;
	int		n1;
	int		n2;	

	stk = t->a->next;
	if (t->a->n > stk->n)
		return (1);
	while (stk->next != t->a)
	{
		n1 = stk->n;
		n2 = stk->next->n;
		if (n1 > n2)
			return (1);
		stk = stk->next;
	}
	return (0);
}

static int	cmd_save(int cmd, t_both **t)
{
	t_stk	*c;

	if (!(*t)->cmd)
	{
		(*t)->cmd = malloc(sizeof(t_stk));
		if (!(*t)->cmd)
			return (1);
		(*t)->cmd->next = NULL;
		c = (*t)->cmd;
	}
	else
	{
		c = (*t)->cmd;
		while (c->next != NULL)
			c = c->next;
		c->next = malloc(sizeof(t_stk));
		if (!c->next)
		{
			stk_free((*t)->cmd);
			return (1);
		}
		c = c->next;
	}
	c->n = cmd;
	c->next = NULL;
	return (0);
}

int	cmd_send(int cmd1, int cmd2, t_both **t)
{
	cmd_get(cmd1, t);
	cmd_save(cmd1, t);
	if (!((*t)->cmd))
	{
		both_free(*t, 1);
		return (1);
	}
	if (cmd2 != 0)
	{
		cmd_get(cmd2, t);
		cmd_save(cmd2, t);
		if (!((*t)->cmd))
		{
			both_free(*t, 1);
			return (1);
		}
	}
	return (0);
}
