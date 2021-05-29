#include "ps.h"

static int	finder(t_stk *first, int cs, int max)
{
	t_stk	*t;
	int	top;
	int bot;
	int ct;
	int cb;

	if (first->n >= cs && first->n <= max)
		return (first->n);
	ct = 1;
	top = 0;
	bot = 0;
	cb = 0;
	t = first->next;
	while (t != first)
	{
		if (t->n >= cs && t->n <= max)
		{
			if (top == 0)
				top = t->n;
			bot = t->n;
			cb = 0;
		}
		if (top == 0)
			ct++;
		cb++;
		t = t->next;
	}
	if (ct <= cb)
		return (top);
	return (bot);
}

/*static int	get_inf(t_stk *first, int n)
{
	t_stk	*t;
	int	top;
	int	bot;

	top = 0;
	if (first->n < n)
		return (first->n);
	t = first->next;
	while (t != first)
	{
		if (t->n < n)
			inf = t->n;
		t = t->next;
	}
	return (inf);
}

static void	prep_n_push(t_both **t, int n)
{
	int inf;

	inf = 0;
	if ((*t)->b != NULL)
		inf = get_inf((*t)->b, n);
	if (inf != 0)
	{
		inf = stk_get((*t)->b, inf) - 1;
		if (inf <= (((*t)->b_size / 2) + 1))
			inf = inf * -1;
	}
	while (inf < 0)
	{
		inf++;
		cmd_print("rb", NULL, t);
	}
	while (inf > 0)
	{
		inf--;
		cmd_print("rrb", NULL, t);
	}
	cmd_print("pb", NULL, t);
}*/

int	chunk_srt(t_both *t, int n, int size)
{
	int	cs;
	int ci;

	cs = 1;
	ci = 0;
	while (n > 0)
	{
		get_on_top(t, &(t->a), finder(t->a, cs, (cs + (size - 1))), 'a');
		cmd_print("pb", NULL, &t);
		ci++;
		if (ci == size)
		{
			ci = 0;
			cs += size;
			n--;
		}
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