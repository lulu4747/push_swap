/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:32:53 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/21 17:32:58 by lfourage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	cmd_get(int cmd, t_both **t)
{
	if (cmd >= SA && cmd <= SS)
		return (swap_read(cmd, t));
	else if (cmd == PA || cmd == PB)
		return (push_read(cmd, t));
	else if (cmd >= RA && cmd <= RRR)
		return (rotate_read(cmd, t));
	return (0);
}

static int	cmd_addone(t_both **t, t_stk **c)
{
	*c = (*t)->cmd;
	while ((*c)->next != NULL)
		*c = (*c)->next;
	(*c)->next = malloc(sizeof(t_stk));
	if (!(*c)->next)
	{
		stk_free((*t)->cmd);
		return (1);
	}
	*c = (*c)->next;
	return (0);
}

static int	cmd_save(int cmd, t_both **t)
{
	t_stk	*c;

	if (!(*t)->cmd)
	{
		(*t)->cmd = malloc(sizeof(t_stk));
		if (!(*t)->cmd)
			return (1);
		(*t)->cmd->next = NULL;
		c = (*t)->cmd;
	}
	else if (cmd_addone(t, &c) != 0)
		return (1);
	c->n = cmd;
	c->next = NULL;
	return (0);
}

int	cmd_send(int cmd1, int cmd2, t_both **t)
{
	cmd_get(cmd1, t);
	cmd_save(cmd1, t);
	if (!((*t)->cmd))
	{
		both_free(*t, 1);
		return (1);
	}
	if (cmd2 != 0)
	{
		cmd_get(cmd2, t);
		cmd_save(cmd2, t);
		if (!((*t)->cmd))
		{
			both_free(*t, 1);
			return (1);
		}
	}
	return (0);
}
