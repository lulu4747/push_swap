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
