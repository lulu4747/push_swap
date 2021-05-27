#ifndef PS_H
# define PS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

# define INT_MIN -2147483648

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

/*--Instructions*/

int	get_ins(char *ins, t_both **t);
int	swap_read(char *ins, t_both **t);
int	push_read(char *ins, t_both **t);
int	rotate_read(char *ins, t_both **t);

/*--Memory--*/

t_both	*init_stk(char **lst, int ac);
t_stk	*stk_get_to(t_stk *stk, int i);
t_stk	*stk_last(t_stk *stk);
int	stk_get(t_stk *stk, int n);
int	stk_min(t_stk *stk);
void	stk_free(t_stk *stk);
void	both_free(t_both *t);

/*--Solver--*/

void	cmd_print(char *s1, char *s2, t_both **t);
void	get_on_top(t_both **t, int n);
int	*stk_cpy_srt(t_stk *stk, int size);
int	solver(t_both *t);

#endif