/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <lfourage@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:51:10 by lfourage          #+#    #+#             */
/*   Updated: 2021/05/31 18:32:19 by lfourage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"
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
	struct s_stk	*next;
	struct s_stk	*prev;
}	t_stk;

typedef struct s_both
{
	int		a_size;
	int		b_size;
	t_stk	*a;
	t_stk	*b;
}	t_both;

/*--Instructions--*/

int		swap_read(int cmd, t_both **t);
int		push_read(int cmd, t_both **t);
int		rotate_read(int cmd, t_both **t);
int		get_ins(char *ins, t_both **t);

/*--Memory--*/

t_both	*init_stk(char **lst, int ac);
t_stk	*stk_last(t_stk *stk);
void	stk_free(t_stk *stk);
void	both_free(t_both *t);
t_stk	*reform(t_stk *a, int size);

/*--Tester--*/

int		is_sorted(t_both **t, int ret);

#endif
