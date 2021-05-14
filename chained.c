#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stk
{
	char	n;
	struct s_stk	*next;
}	t_stk;

t_stk	*init_stk(char *lst)
{
	t_stk	*stk;
	t_stk	*top;
	int	i;

	i = 0;
	stk = malloc(sizeof(t_stk));
	if (!stk)
		return (NULL);
	top = stk;
	stk->n = lst[i];
	while (lst[++i])
	{
		stk->next = malloc(sizeof(t_stk));
		stk = stk->next;
		if (!stk)
			return (NULL);
		stk->n = lst[i];
	}
	stk->next = top;
	return (top);
}

int	swap(t_stk *stk)
{
	char	tmp;

	if (stk->next == stk)
		return (1);
	tmp = stk->n;
	stk->n = stk->next->n;
	stk->next->n = tmp;
	return (0);
}

int	push(t_stk *fr, t_stk *to)
{
	t_stk *cut;

	if (fr->next == fr)
	{
		fr->next = to;
		to = fr;
		return (0);
	}
	cut = fr;
	while (cut->next != fr)
		cut = cut->next;
	cut->next = fr->next;
	if (!to)
		fr->next = fr;
	else
		fr->next = to;
	to = fr;
	return (0);
}

int main(int ac, char **av)
{
	t_stk	*top;
	t_stk	*a;
	t_stk	*b;

	a = init_stk(av[1]);
	b = NULL;
	top = a;
	printf("\n%c\n", a->n);
	a = a->next;
	while (a != top)
	{
		printf("%c\n", a->n);
		a = a->next;
	}
	push(a, b);
	printf("\n%c\n", a->n);
	a = a->next;
	while (a != top)
	{
		printf("%c\n", a->n);
		a = a->next;
	}
	return (0);
}