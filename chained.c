#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stk
{
	int	n;
	struct s_stk	*next;
}	t_stk;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long ft_atol(char *n)
{
	int	i;
	long	r;

	r = 0;
	i = ft_strlen(n) - 1;
	while (i >= 0)
	{
		r = (r * 10) + (n[i] - '0');
		i--;
	}
	return (r);
}

int	ft_atoi(char *n)
{
	int	i;
	int	r;

	r = 0;
	i = ft_strlen(n) - 1;
	while (i >= 0)
	{
		r = (r * 10) + (n[i] - '0');
		i--;
	}
	return (r);
}

t_stk	*init_stk(char **lst, int ac)
{
	t_stk	*stk;
	t_stk	*top;
	int	i;

	i = 1;
	stk = malloc(sizeof(t_stk));
	if (!stk)
		return (NULL);
	top = stk;
	stk->n = ft_atoi(lst[1]);
	if (stk->n != ft_atol(lst[1]))
	{
		printf("Error\nValue > INT_MAX or value < INT_MIN\n");
		return (NULL);
	}
	while (++i < ac)
	{
		stk->next = malloc(sizeof(t_stk));
		stk = stk->next;
		if (!stk)
			return (NULL);
		stk->n = ft_atoi(lst[i]);
		if (stk->n != ft_atol(lst[i]))
		{
			printf("Error\nValue > INT_MAX or value < INT_MIN\n");
			return (NULL);
		}
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

int	push(t_stk **fr, t_stk **to)
{
	t_stk *cut;
	t_stk *tmp;

	if ((*fr)->next == *fr)
	{
		(*fr)->next = *to;
		*to = *fr;
		return (0);
	}
	cut = *fr;
	while (cut->next != *fr)
		cut = cut->next;
	cut->next = (*fr)->next;
	if (!(*to))
	{
		(*fr)->next = *fr;
		*to = *fr;
	}
	else
	{
		(*fr)->next = *to;
		tmp = *to;
		while (tmp->next != *to)
			tmp = tmp->next;
		tmp->next = *fr;
		*to = *fr;
	}
	*fr = cut->next;
	return (0);
}

t_stk	*rotate(t_stk *stk)
{
	return (stk->next);
}

t_stk	*r_rotate(t_stk *stk)
{
	t_stk	*top;

	top = stk;
	while (top->next != stk)
		top = top->next;
	return (top);
}

int main(int ac, char **av)
{
	t_stk	*top_a;
	t_stk	*top_b;
	t_stk	*a;
	t_stk	*b;


	int	size[2];
	int	tmp;

	a = init_stk(av, ac);
	b = NULL;
	top_a = a;
	size[0] = 0;
	size[1] = 0;
	printf("\n%d\n", a->n);
	a = a->next;
	size[0]++;
	while (a != top_a)
	{
		printf("%d\n", a->n);
		a = a->next;
		size[0]++;
	}
	//
	top_b = top_a;
	top_a = a->next;
	push(&a, &b);
	size[0]--;
	size[1]++;
	//
	//
	top_b = top_a;
	top_a = a->next;
	push(&a, &b);
	size[0]--;
	size[1]++;
	//
	printf("\nA :\n\n%d\n", a->n);
	a = a->next;
	while (a != top_a)
	{
		printf("%d", a->n);
		printf("\n");
		a = a->next;
	}
	printf("\nB :\n\n%d\n", b->n);
	b = b->next;
	while (b != top_b)
	{
		printf("%d", b->n);
		printf("\n");
		b = b->next;
		tmp--;
	}
	return (0);
}