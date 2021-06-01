/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:50:55 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/01 12:01:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

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

static int	reverse_read(char *ins, t_both **t)
{
	if (ins[2] == 0)
	{
		if ((*t)->a_size > 0)
			(*t)->a = rotate((*t)->a);
		if ((*t)->b_size > 0)
			(*t)->b = rotate((*t)->b);
	}
	else if (ins[3] != 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (ins[2] == 'a' && (*t)->a_size > 0)
		(*t)->a = r_rotate((*t)->a);
	else if (ins[2] == 'b' && (*t)->b_size > 0)
		(*t)->b = r_rotate((*t)->b);
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	rotate_read(char *ins, t_both **t)
{
	if (ins[1] == 'r')
		return (reverse_read(ins, t));
	else if (ins[2] != 0)
		write(2, "Error\n", 6);
	else if (ins[1] == 'a')
	{
		if ((*t)->a_size > 0)
			(*t)->a = rotate((*t)->a);
		return (0);
	}
	else if (ins[1] == 'b')
	{
		if ((*t)->b_size > 0)
			(*t)->b = rotate((*t)->b);
		return (0);
	}
	else
		write(2, "Error\n", 6);
	return (1);
}
