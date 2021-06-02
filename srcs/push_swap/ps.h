/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:48:44 by lfourage          #+#    #+#             */
/*   Updated: 2021/06/03 00:46:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

# define SA		1
# define SB		2
# define SS		3
# define RA		4
# define RB		5
# define RR		6
# define PA		7
# define PB		8
# define RRA	9
# define RRB	10
# define RRR	11

typedef struct s_stk
{
	int				n;
	struct s_stk	*prev;
	struct s_stk	*next;
}	t_stk;

typedef struct s_both
{
	int		a_size;
	int		b_size;
	t_stk	*a;
	t_stk	*b;
	t_stk	*cmd;
}	t_both;

/*--Instructions*/

int		cmd_send(int cmd1, int cmd2, t_both **t);
int		cmd_get(int cmd, t_both **t);
int		swap_read(int cmd, t_both **t);
int		push_read(int cmd, t_both **t);
int		rotate_read(int cmd, t_both **t);

/*--Memory--*/

t_both	*init_stk(char **lst, int ac);
t_stk	*stk_get_to(t_stk *stk, int i);
t_stk	*stk_last(t_stk *stk);
int		stk_get(t_stk *stk, int n);
int		stk_min(t_stk *stk);
void	stk_free(t_stk *stk);
void	both_free(t_both *t, int err);

/*--Solver--*/

void	get_on_top(t_both *t, t_stk **stk, int n, int cmd);
int		fnd(t_stk *first, int cs, int max);
int		*stk_cpy_srt(t_stk *stk, int size);
int		sorted(t_both *t);
int		solver(t_both **t);
int		chunk_srt(t_both *t);

#endif
