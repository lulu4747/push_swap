/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:49:49 by lfourage          #+#    #+#             */
/*   Updated: 2021/05/31 12:50:09 by lfourage         ###   ########lyon.fr   */
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
