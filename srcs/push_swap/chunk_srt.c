#include "ps.h"

static int	finder(t_stk *first, int cs)
{
	t_stk	*t;
	int	top;
	int ct;
	int bot;
	int cb;

	if (first->n >= cs && first->n <= (cs + 19))
		return (first->n);
	ct = 1;
	top = 0;
	bot = 0;
	cb = 0;
	t = first->next;
	while (t != first)
	{
		if (t->n >= cs && t->n <= (cs + 19))
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
	printf("top : %d	bot : %d\n", top, bot);
	if (ct <= cb)
		return (top);
	return (bot);
}

static int	get_inf(t_stk *first, int n)
{
	t_stk	*t;
	int	inf;

	inf = 0;
	if (first->n < n)
		inf = first->n;
	t = first->next;
	while (t != first)
	{
		if (t->n < n && t->n > inf)
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
		inf = get_inf((*t)->a, n);
	if (inf != 0)
	{
		inf = stk_get((*t)->b, inf) - 1;
		if (inf <= (((*t)->b_size / 2) + 1))
			inf = inf * -1;
	}
	while (inf < 0)
	{
		inf++;
		cmd_print("ra", NULL, t);
	}
	while (inf > 0)
	{
		inf--;
		cmd_print("rra", NULL, t);
	}
	cmd_print("pb", NULL, t);
}

int	chunk_srt(t_both *t, int n)
{
	int	cs;
	int ci;

	cs = 1;
	ci = 0;
	while (n > 0)
	{
		get_on_top(t, &(t->a), finder(t->a, cs));
		prep_n_push(&t, t->a->n);
		ci++;
		if (ci == 20)
		{
			ci = 0;
			cs += 20;
			n--;
		}
	}
	while (t->a_size > 0)
	{
		get_on_top(t, &(t->a), cs);
		cmd_print("pb", NULL, &t);
		cs++;
	}
	cs--;
	while (t->b_size > 0)
	{
		get_on_top(t, &(t->b), cs);
		cmd_print("pa", NULL, &t);
		cs--;
	}
	return (1);
}