#include "ps.h"

static t_both	*three_srt(t_both *t)
{
	if (t->a->n < t->a->next->n)
	{
		if (t->a->n < t->a->next->next->n)
			cmd_print("sa", "ra", &t);
		else
			cmd_print("rra", NULL, &t);
	}
	else
	{
		if (t->a->n < t->a->next->next->n)
			cmd_print("sa", NULL, &t);
		else if (t->a->next->n < t->a->next->next->n)
			cmd_print("ra", NULL, &t);
		else
			cmd_print("sa", "rra", &t);
	}
	return (t);
}

static int	quick(t_both *t)
{
	int	minpos;

	while (t->a_size > 3)
	{
		minpos = stk_get(t->a, stk_min(t->a));
		if (minpos > 3)
		{
			while (t->a->n != stk_min(t->a))
				cmd_print("rra", NULL, &t);
		}
		else
		{
			while (t->a->n != stk_min(t->a))
				cmd_print("ra", NULL, &t);
		}
		cmd_print("pb", NULL, &t);
	}
	t = three_srt(t);
	if (t->b_size == 2 && t->b->n < t->b->next->n)
		cmd_print("sb", NULL, &t);
	while (t->b_size > 0)
		cmd_print("pa", NULL, &t);
	while (t->a->n != stk_min(t->a))
		cmd_print("ra", NULL, &t);
	return (1);
}

static int	simple(t_both *t)
{
	while (t->a_size > 0)
	{
		get_on_top(&t, stk_min(t->a));
		cmd_print("pb", NULL, &t);
	}
	while (t->b_size > 0)
		cmd_print("pa", NULL, &t);
	return (1);
}

static t_stk *reform(t_stk *a, int size)
{
	int	i;
	int	*t;
	t_stk	*first;

	first = a;
	t = stk_cpy_srt(a, size);
	if (!t)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (a->n != t[i])
			a = a->next;
		a->n = i + 1;
		a = a->next;
	}
	free(t);
	a = first;
	return (a);
}

int	solver(t_both *t)
{
	if (t->a_size <= 5)
		return (quick(t));
	else if (t->a_size <= 20)
		return (simple(t));
	t->a = reform(t->a, t->a_size);
	if (!t->a)
		return (-1);
	return (1);
}