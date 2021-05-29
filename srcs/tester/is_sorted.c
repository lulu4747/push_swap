#include "tester.h"

int is_sorted(t_both *t)
{
	t_stk *stk;
	int	n1;
	int	n2;	

	if (t->b_size != 0)
	{
		write(2, "KO\n", 3);
		return (1);
	}
	stk = t->a;
	stk = stk->next;
	if (t->a->n > stk->n)
	{
		write(2, "KO\n", 3);
		return (1);
	}
	while (stk->next != t->a)
	{
		n1 = stk->n;
		n2 = stk->next->n;
		if (n1 > n2)
		{
			write(2, "KO\n", 3);
			return (1);
		}
		stk = stk->next;
	}
	write(1, "OK\n", 3);
	both_free(t);
	return (0);
}