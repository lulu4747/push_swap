/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:49:58 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/01 15:26:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
