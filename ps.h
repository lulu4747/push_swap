#ifndef PS_H
# define PS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./srcs/gnl/get_next_line.h"


typedef	struct	s_stk
{
	int	n;
	struct s_stk	*next;
}	t_stk;

typedef	struct	s_both
{
	int	a_size;
	int	b_size;
	t_stk	*a;
	t_stk	*b;
}	t_both;

t_both	*init_stk(char **lst, int ac);
int	swap(t_stk *stk);
int	push(t_stk **fr, t_stk **to);
t_stk	*rotate(t_stk *stk);
t_stk	*r_rotate(t_stk *stk);

#endif