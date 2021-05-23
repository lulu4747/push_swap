#include "ps.h"

static t_stk	*stk_element(char *nb)
{
	t_stk	*stk;

	stk = malloc(sizeof(t_stk));
	if (!stk)
		return (NULL);
	stk->n = ft_atoi(nb);
	if (stk->n != ft_atol(nb))
	{
		write(2, "Error\nn > INT_MAX or n < INT_MIN\n", 35);
		return (NULL);
	}
	return (stk);
}

static t_stk	*build_stk(char **lst, int ac)
{
	t_stk	*stk;
	t_stk	*top;
	int	i;

	i = 1;
	stk = stk_element(lst[1]);
	if (!stk)
		return (NULL);
	top = stk;
	while (++i < ac)
	{
		stk->next = stk_element(lst[i]);
		stk = stk->next;
		if (!stk)
			return (NULL);
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