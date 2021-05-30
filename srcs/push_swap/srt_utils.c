#include "ps.h"

int	*stk_cpy_srt(t_stk *stk, int size)
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

int	get_ins(char *ins, t_both **t)
{
	if (ins[0] == 's')
		return (swap_read(ins, t));
	else if (ins[0] == 'p')
		return (push_read(ins, t));
	else if (ins[0] == 'r')
		return (rotate_read(ins, t));
	return (0);
}

int	sorted(t_both *t)
{
	t_stk	*stk;
	int		n1;
	int		n2;	

	stk = t->a;
	stk = stk->next;
	if (t->a->n > stk->n)
		return (1);
	while (stk->next != t->a)
	{
		n1 = stk->n;
		n2 = stk->next->n;
		if (n1 > n2)
			return (1);
		stk = stk->next;
	}
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

void	get_on_top(t_both *t, t_stk **stk, int n, char s)
{
	int		pos;
	int		size;
	char	str[4];

	str[0] = 'r';
	if (s == 'a')
		size = t->a_size;
	else
		size = t->b_size;
	pos = stk_get((*stk), n);
	if ((pos > size / 2 && !(size % 2)) || pos > ((size / 2) + 1))
	{
		str[1] = 'r';
		str[2] = s;
		str[3] = 0;
		while ((*stk)->n != n)
			cmd_print(str, NULL, &t);
	}
	else
	{
		str[1] = s;
		str[2] = 0;
		while ((*stk)->n != n)
			cmd_print(str, NULL, &t);
	}
}
