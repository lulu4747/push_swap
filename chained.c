#include "ps.h"

static t_stk	*build_stk(char **lst, int ac)
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
		write(2, "Error\nn > INT_MAX or n < INT_MIN\n", 35);
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
			write(2, "Error\nn > INT_MAX or n < INT_MIN\n", 35);
			return (NULL);
		}
	}
	stk->next = top;
	return (top);
}

t_both	*init_stk(char **lst, int ac)
{
	t_both	*r;

	r = malloc(sizeof(t_both));
	if (!r)
		return (NULL);
	r->a = build_stk(lst, ac);
	if (!(r->a))
	{
		free(r);
		return (NULL);
	}
	r->b = NULL;
	r->a_size = ac - 1;
	r->b_size = 0;
	return (r);
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
		cut = *to;
		while (cut->next != *to)
			cut = cut->next;
		(*fr)->next = *to;
		*to = *fr;
		*fr = NULL;
		cut->next = *to;
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
		while (((*to)->next) != tmp)
			*to = ((*to)->next);
		((*to)->next) = *fr;
		*to = *fr;
	}
	*fr = cut->next;
	return (0);
}

t_stk	*rotate(t_stk *stk)
{
	t_stk	*next;

	next = stk->next;
	return (next);
}

t_stk	*r_rotate(t_stk *stk)
{
	t_stk	*top;

	top = stk;
	while (top->next != stk)
		top = top->next;
	return (top);
}

static int	s(char *ins, t_both **t)
{
	int	r;

	r = 1;
	if (ins[2] != 0)
		write(2, "Invalid instruction\n", 20);
	else if (ins[1] == 'a')
	{
		if ((*t)->a_size > 1)
			return (swap((*t)->a));
	}
	else if (ins[1] == 'b')
	{
		if ((*t)->b_size > 1)
			return (swap((*t)->b));
	}
	else if (ins[1] == 's')
	{
		if ((*t)->a_size > 1)
			r = swap((*t)->a);
		if ((*t)->b_size > 1 && (r + swap((*t)->b) == 0))
			return (0);
	}
	else
		write(2, "Invalid instruction\n", 20);
	return (1);
}

static int	p(char *ins, t_both **t)
{
	if (ins[2] != 0)
		write(2, "Invalid instruction\n", 20);
	else if (ins[1] == 'a')
	{
		if ((*t)->a_size >= 1)
		{
			(*t)->a_size--;
			(*t)->b_size++;
			return (push(&((*t)->a), &((*t)->b)));
		}
		else
			return (1);
	}
	else if (ins[1] == 'b')
	{
		if ((*t)->b_size >= 1)
		{
			(*t)->b_size--;
			(*t)->a_size++;
			return (push(&((*t)->b), &((*t)->a)));
		}
		else
			return (1);
	}
	else
		write(2, "Invalid instruction\n", 20);
	return (1);
}

static int	r_r(char *ins, t_both **t)
{
	if (ins[3] != 0)
	{
		write(2, "Invalid instruction\n", 20);
		return (1);
	}
	else if (ins[2] == 'a')
		(*t)->a = r_rotate((*t)->a);
	else if (ins[2] == 'b')
		(*t)->b = r_rotate((*t)->b);
	else
	{
		write(2, "Invalid instruction\n", 20);
		return (1);
	}
	return (0);
}

static int	r(char *ins, t_both **t)
{
	if (ins[1] == 'r')
		return (r_r(ins, t));
	else if (ins[2] != 0)
		write(2, "Invalid instruction\n", 20);
	else if (ins[1] == 'a')
	{
		(*t)->a = rotate((*t)->a);
		return (0);
	}
	else if (ins[1] == 'b')
	{
		(*t)->b = rotate((*t)->b);
		return (0);
	}
	else
		write(2, "Invalid instruction\n", 20);
	return (1);
}

int	get_ins(char *ins, t_both **t)
{
	if (ins[0] == 's')
		return (s(ins, t));
	else if (ins[0] == 'p')
		return (p(ins, t));
	else if (ins[0] == 'r')
		return (r(ins, t));
	else
		write(2, "Invalid instruction\n", 20);
	return (0);
}

static void visual(t_both *t)
{
	int n;
	t_stk	*a;
	t_stk	*b;

	a = t->a;
	b = t->b;
	if (t->a_size > t->b_size)
		n = t->a_size;
	else
		n = t->b_size;
	printf("	A		B\n\n");
	while (n > 0)
	{
		if (t->a_size >= n)
		{
			printf("	%d", a->n);
			a = a->next;
		}
		else
			printf("	");
		if (t->b_size >= n)
		{
			printf("		%d", b->n);
			b = b->next;
		}
		printf("\n");
		n--;
	}
	printf("_____________________________________\n");
}

static int	ft_dup_check(int ac, char **av)
{
	int	i;
	int	j;
	char	*s1;
	char	*s2;

	i = 1;
	j = ac - 1;
	while (i < j)
	{
		j = i + 1;
		s1 = av[i];
		while (j < ac)
		{
			s2 = av[j];
			if (!ft_strcmp(s1, s2))
			{
				write(2, "2 or more occurences of the", 27);
				write(2, " same number\nClosing program\n", 28);
				return (1);
			}
			if (ft_is_number(s1) != 0)
			{
				write(2, "Non-numerical value found\n", 26);
				write(2, "Closing program\n", 28);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_both	*t;
	char	*line;
	int	ret;

	ret = 1;
	t = NULL;
	if (ac > 2 && !ft_dup_check(ac, av))
		t = init_stk(av, ac);
	if (!t)
		return (-1);
	visual(t);
	while (ret)
	{
		ret = get_next_line(0, &line);
		get_ins(line, &t);
		visual(t);
		free(line);
	}
	return (0);
}