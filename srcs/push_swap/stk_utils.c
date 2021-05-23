#include "ps.h"

t_stk	*stk_last(t_stk *stk)
{
	t_stk	*last;

	last = stk;
	while (last->next != stk)
		last = last->next;
	return (last);
}