/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:49:08 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/01 17:48:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static t_stk	*rotate(t_stk *stk)
{
	t_stk	*next;

	next = stk->next;
	return (next);
}

static t_stk	*r_rotate(t_stk *stk)
{
	t_stk	*top;

	top = stk;
	while (top->next != stk)
		top = top->next;
	return (top);
}

int	rotate_read(int cmd, t_both **t)
{
	if ((cmd == RA || cmd == RR) && (*t)->a_size > 0)
		(*t)->a = rotate((*t)->a);
	if ((cmd == RB || cmd == RR) && (*t)->b_size > 0)
		(*t)->b = rotate((*t)->b);
	if ((cmd == RRA || cmd == RRR) && (*t)->a_size > 0)
		(*t)->a = r_rotate((*t)->a);
	if ((cmd == RRB || cmd == RRR) && (*t)->b_size > 0)
		(*t)->b = r_rotate((*t)->b);
	return (0);
}
