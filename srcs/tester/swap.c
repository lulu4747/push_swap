#include "tester.h"

static int	swap(t_stk *stk)
{
	char	tmp;

	if (stk->next == stk)
		return (1);
	tmp = stk->n;
	stk->n = stk->next->n;
	stk->next->n = tmp;
	return (0);
}

int	swap_read(char *ins, t_both **t)
{
	int	r;

	r = 1;
	if (ins[2] != 0)
		write(2, "Error\n", 6);
	else if (ins[1] == 'a')
	{
		if ((*t)->a_size > 1)
			return (swap((*t)->a));
	}
	else if (ins[1] == 'b')
	{
		if ((*t)->b_size > 1)
			return (swap((*t)->b));
	}
	else if (ins[1] == 's')
	{
		if ((*t)->a_size > 1)
			r = swap((*t)->a);
		if ((*t)->b_size > 1 && (r + swap((*t)->b) == 0))
			return (0);
	}
	else
		write(2, "Error\n", 6);
	return (1);
}