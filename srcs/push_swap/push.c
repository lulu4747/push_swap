/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:48:54 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/01 15:19:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	empty_stk(t_stk **fr, t_stk **to)
{
	t_stk	*cut;

	cut = stk_last(*to);
	(*fr)->next = *to;
	*to = *fr;
	*fr = NULL;
	cut->next = *to;
	return (0);
}

static int	push(t_stk **fr, t_stk **to)
{
	t_stk	*cut;

	if ((*fr)->next == *fr)
		return (empty_stk(fr, to));
	cut = stk_last(*fr);
	cut->next = (*fr)->next;
	if (!(*to))
	{
		(*fr)->next = *fr;
		*to = *fr;
	}
	else
	{
		(*fr)->next = *to;
		*to = stk_last(*to);
		((*to)->next) = *fr;
		*to = *fr;
	}
	*fr = cut->next;
	return (0);
}

int	push_read(int cmd, t_both **t)
{
	if (cmd == PA && (*t)->b_size >= 1)
	{
		(*t)->a_size++;
		(*t)->b_size--;
		return (push(&((*t)->b), &((*t)->a)));
	}
	else if (cmd == PB && (*t)->a_size >= 1)
	{
		(*t)->b_size++;
		(*t)->a_size--;
		return (push(&((*t)->a), &((*t)->b)));
	}
	return (1);
}
