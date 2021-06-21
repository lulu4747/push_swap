/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:50:52 by lfourage          #+#    #+#             */
/*   Updated: 2021/05/31 12:50:53 by lfourage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int	empty_stk(t_stk **fr, t_stk **to)
{
	t_stk	*cut;

	cut = (*to)->prev;
	(*fr)->next = *to;
	(*to)->prev = *fr;
	*to = *fr;
	*fr = NULL;
	cut->next = *to;
	(*to)->prev = cut;
	return (0);
}

static void	nxt_prv(t_stk **fr, t_stk **to)
{
	(*fr)->next = *to;
	(*to)->prev = *fr;
}

static int	push(t_stk **fr, t_stk **to)
{
	t_stk	*cut;

	if ((*fr)->next == *fr)
		return (empty_stk(fr, to));
	cut = (*fr)->prev;
	cut->next = (*fr)->next;
	(*fr)->next->prev = cut;
	if (!(*to))
		nxt_prv(fr, fr);
	else
	{
		nxt_prv(fr, to);
		*to = stk_last(*to);
		nxt_prv(to, fr);
	}
	*to = *fr;
	*fr = cut->next;
	(*fr)->prev = cut;
	return (0);
}

int	push_read(int cmd, t_both **t)
{
	if (cmd == PA)
	{
		if ((*t)->b_size > 0)
		{
			(*t)->a_size++;
			(*t)->b_size--;
			return (push(&((*t)->b), &((*t)->a)));
		}
		return (0);
	}
	else if (cmd == PB)
	{
		if ((*t)->a_size > 0)
		{
			(*t)->b_size++;
			(*t)->a_size--;
			return (push(&((*t)->a), &((*t)->b)));
		}
		return (0);
	}
	return (1);
}
