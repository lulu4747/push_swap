#include "tester.h"

t_stk	*stk_last(t_stk *stk)
{
	t_stk	*last;

	last = stk;
	while (last->next != stk)
		last = last->next;
	return (last);
}

int	get_ins(char *ins, t_both **t)
{
	if (ins == NULL)
		return (0);
	if (ins[0] == 's')
		return (swap_read(ins, t));
	else if (ins[0] == 'p')
		return (push_read(ins, t));
	else if (ins[0] == 'r')
		return (rotate_read(ins, t));
	else if (ins[0] != 0)
		write(2, "Error\n", 6);
	return (0);
}
