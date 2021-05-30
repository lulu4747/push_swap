#include "ps.h"

static int	fnd(t_stk *first, t_stk *t, int cs, int max)
{
	int		count[4];

	if (first->n >= cs && first->n <= max)
		return (first->n);
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 1;
	while (t != first)
	{
		if (t->n >= cs && t->n <= max)
		{
			if (count[0] == 0)
				count[0] = t->n;
			count[1] = t->n;
			count[2] = 0;
		}
		if (count[0] == 0)
			(count[3])++;
		(count[2])++;
		t = t->next;
	}
	if (count[3] <= count[2])
		return (count[0]);
	return (count[1]);
}

int	chunk(t_both *t, int c, int s)
{
	int	i;

	i = 0;
	while (i < s)
	{
		get_on_top(t, &(t->a), fnd(t->a, t->a->next, c, (c + (s - 1))), 'a');
		cmd_print("pb", NULL, &t);
		i++;
	}
	return (s);
}

int	chunk_srt(t_both *t, int n, int size)
{
	int	cs;

	cs = 1;
	while (n > 0)
	{
		cs += chunk(t, cs, size);
		n--;
	}
	while (t->a_size > 0)
	{
		get_on_top(t, &(t->a), cs, 'a');
		cmd_print("pb", NULL, &t);
		cs++;
	}
	cs--;
	while (t->b_size > 0)
	{
		get_on_top(t, &(t->b), cs, 'b');
		cmd_print("pa", NULL, &t);
		cs--;
	}
	return (1);
}
