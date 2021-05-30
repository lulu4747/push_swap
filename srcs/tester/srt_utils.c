#include "tester.h"

t_stk	*stk_last(t_stk *stk)
{
	t_stk	*last;

	last = stk;
	while (last->next != stk)
		last = last->next;
	return (last);
}

static int	*stk_cpy_srt(t_stk *stk, int size)
{
	int	i;
	int	*t;

	t = malloc(sizeof(int) * size);
	if (!t)
	{
		stk_free(stk);
		return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		t[i] = stk->n;
		stk = stk->next;
	}
	t = ft_sort(t, size);
	return (t);
}

t_stk	*reform(t_stk *a, int size)
{
	int		i;
	int		*t;
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
