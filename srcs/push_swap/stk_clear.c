/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:49:40 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/01 19:28:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

static t_stk	*cmd_opti(t_stk *first, int c)
{
	t_stk	*r;
	t_stk	*f;
	int		bl;

	bl = 0;
	r = first->next;
	while (r != NULL && r->n != c + 1 && bl != 2)
	{
		if (r->n == PA)
			bl++;
		if (c == RA && (r->n == RRA || r->n == RRB || r->n == SB || r->n == PB))
			bl = 2;
		if (c == RRA && (r->n == RA || r->n == RB || r->n == SB || r->n == PB))
			bl = 2;
		r = r->next;
	}
	if (r == NULL || bl == 2)
		return (first);
	first->n += 2;
	f = first;
	while (f->next != r)
		f = f->next;
	f->next = r->next;
	free(r);
	return (first);
}

static void	printer(int cmd)
{
	if (cmd == SA)
		printf("sa\n");
	if (cmd == SB)
		printf("sb\n");
	if (cmd == SS)
		printf("ss\n");
	if (cmd == RA)
		printf("ra\n");
	if (cmd == RB)
		printf("rb\n");
	if (cmd == RR)
		printf("rr\n");
	if (cmd == PA)
		printf("pa\n");
	if (cmd == PB)
		printf("pb\n");
	if (cmd == RRA)
		printf("rra\n");
	if (cmd == RRB)
		printf("rrb\n");
	if (cmd == RRR)
		printf("rrr\n");
}

static void	cmd_print(t_stk *cmd)
{
	t_stk	*fre;

	while (cmd != NULL)
	{
		if (cmd->n == RA || cmd->n == RRA)
			cmd = cmd_opti(cmd, cmd->n);
		printer(cmd->n);
		fre = cmd;
		cmd = cmd->next;
		free(fre);
	}
}

void	both_free(t_both *t, int err)
{
	if (t->a != NULL)
		stk_free(t->a);
	if (t->b != NULL)
		stk_free(t->b);
	if (err == 0 && t->cmd != NULL)
		cmd_print(t->cmd);
	else if (t->cmd != NULL)
		stk_free(t->cmd);
	free(t);
}
