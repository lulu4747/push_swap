#include "ps.h"

int	get_ins(char *ins, t_both **t)
{
	if (ins[0] == 's')
		return (swap_read(ins, t));
	else if (ins[0] == 'p')
		return (push_read(ins, t));
	else if (ins[0] == 'r')
		return (rotate_read(ins, t));
	else
		write(2, "Invalid instruction\n", 20);
	return (0);
}

static void	auto(char *s1, char *s2, t_both **t)
{
	get_ins(s1, t);
	printf("%s\n", s1);
	if (s2 != NULL)
	{
		get_ins(s2, t);
		printf("%s\n", s2);
	}
}

static t_both	*three_srt(t_both *t)
{
	if (t->a->n < t->a->next->n)
	{
		if (t->a->n < t->a->next->next->n)
			auto("sa", "ra", &t);
		else
			auto("rra", NULL, &t);
	}
	else
	{
		if (t->a->n < t->a->next->next->n)
			auto("sa", NULL, &t);
		else if (t->a->next->n < t->a->next->next->n)
			auto("ra", NULL, &t);
		else
			auto("sa", "rra", &t);
	}
	return (t);
}

static void	quick(t_both *t)
{
	int	minpos;

	while (t->a_size > 3)
	{
		minpos = stk_get(t->a, stk_min(t->a));
		if (minpos > 3)
		{
			while (t->a->n != stk_min(t->a))
				auto("rra", NULL, &t);
		}
		else
		{
			while (t->a->n != stk_min(t->a))
				auto("ra", NULL, &t);
		}
		auto("pb", NULL, &t);
	}
	t = three_srt(t);
	if (t->b_size == 2 && t->b->n < t->b->next->n)
		auto("sb", NULL, &t);
	if (t->b_size > 0)
		auto("pa", NULL, &t);
}

int	solver(t_both *t)
{
	if (t->a_size <= 5)
		return (quick(t));
}