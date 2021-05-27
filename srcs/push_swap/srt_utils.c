#include "ps.h"

int	*stk_cpy_srt(t_stk *stk, int size)
{
	int i;
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

void	cmd_print(char *s1, char *s2, t_both **t)
{
	get_ins(s1, t);
	printf("%s\n", s1);
	if (s2 != NULL)
	{
		get_ins(s2, t);
		printf("%s\n", s2);
	}
}

void	get_on_top(t_both **t, int n)
{
	int pos;

	pos = stk_get((*t)->a, n);
	if (pos > (*t)->a_size / 2 && !((*t)->a_size % 2))
	{
		while ((*t)->a->n != n)
			cmd_print("ra", NULL, t);
	}
	else
	{
		while ((*t)->a->n != n)
			cmd_print("rra", NULL, t);
	}
}