#include "tester.h"

static int	empty_stk(t_stk **fr, t_stk **to)
{
	t_stk	*cut;

	cut = stk_last(*to);
	(*fr)->next = *to;
	*to = *fr;
	*fr = NULL;
	cut->next = *to;
	return (0);
}

static int	push(t_stk **fr, t_stk **to)
{
	t_stk	*cut;

	if ((*fr)->next == *fr)
		return (empty_stk(fr, to));
	cut = stk_last(*fr);
	cut->next = (*fr)->next;
	if (!(*to))
	{
		(*fr)->next = *fr;
		*to = *fr;
	}
	else
	{
		(*fr)->next = *to;
		*to = stk_last(*to);
		((*to)->next) = *fr;
		*to = *fr;
	}
	*fr = cut->next;
	return (0);
}

int	push_read(char *ins, t_both **t)
{
	if (ins[2] != 0)
		write(2, "Error\n", 6);
	else if (ins[1] == 'a')
	{
		if ((*t)->b_size >= 1)
		{
			(*t)->a_size++;
			(*t)->b_size--;
			return (push(&((*t)->b), &((*t)->a)));
		}
		return (1);
	}
	else if (ins[1] == 'b')
	{
		if ((*t)->a_size >= 1)
		{
			(*t)->b_size++;
			(*t)->a_size--;
			return (push(&((*t)->a), &((*t)->b)));
		}
		return (1);
	}
	else
		write(2, "Error\n", 6);
	return (1);
}
