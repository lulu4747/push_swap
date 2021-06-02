/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:51:05 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/03 01:54:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	stk_free(t_stk *stk)
{
	t_stk	*fre;
	t_stk	*nxt;

	fre = stk->next;
	while (fre != NULL && fre != stk)
	{
		nxt = fre->next;
		free(fre);
		fre = nxt;
	}
	free(stk);
}

void	both_free(t_both *t)
{
	if (t->a != NULL)
		stk_free(t->a);
	if (t->b != NULL)
		stk_free(t->b);
	free(t);
}
