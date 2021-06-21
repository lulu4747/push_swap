/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:51:08 by lfourage          #+#    #+#             */
/*   Updated: 2021/05/31 12:51:09 by lfourage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	swap(t_stk *stk)
{
	char	tmp;

	tmp = stk->n;
	stk->n = stk->next->n;
	stk->next->n = tmp;
}

int	swap_read(int cmd, t_both **t)
{
	if ((cmd == SA || cmd == SS) && (*t)->a_size > 1)
		swap((*t)->a);
	if ((cmd == SB || cmd == SS) && (*t)->b_size > 1)
		swap((*t)->b);
	return (0);
}
