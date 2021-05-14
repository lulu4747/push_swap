/*__________________________________________________________________________________*/
/* .h																				*/
/*__________________________________________________________________________________*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int	*fs;
	int	bsize;
	int	fsize;
}				t_stack;

/*__________________________________________________________________________________*/
/*										libft										*/
/*__________________________________________________________________________________*/

int		ft_atoi(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i])
	{
		r += (r * 10) + (str[i] - '0')
		i++;
	}
	return (r);
}

int	nbr_len(n)
{
	int i;

	i = 0;
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_strlen(str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int	len;
	char	*r;

	len = nbr_len(n);
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	r[len] = 0;
	len--;
	while (len > 0)
	{
		r[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	r[len] = n + '0';
	return (r);
}

char	*ft_strdup(char *src)
{
	int	*len;
	int i;
	char	*r;

	len = ft_strlen(src);
	r = malloc(sizeof(char) * (len + 1))
	if (!r)
		return (NULL);
	i = 0;
	r[len] = 0;
	while (i < len)
	{
		r[i] = str[i]
		i++;
	}
	return (r);
}

/*__________________________________________________________________________________*/
/*									src #1											*/
/*__________________________________________________________________________________*/

t_stack	*get_stack(t_stack	*stk, int *ac, char **av)
{
	int	i;

	i = 0;
	stk = malloc(sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->fs = malloc(sizeof(int) * ac);
	if (!(stk->fs))
	{
		free(stk);
		return (NULL);
	}
	while (i < ac)
	{
		stk->fs[i] = ft_atoi(av[i]);
		i++;
	}
	stk->bsize = 0;
	stk->fsize = ac - 1;
	return (stk);
}

/*__________________________________________________________________________________*/
/* 									src #2											*/
/*__________________________________________________________________________________*/

int		is_sorted(t_stack	*stk)
{
	int	i;
	int	n;

	if (stk->bsize)
		return (0);
	i = 0;
	n = stk->fs[i];
	while (++i < stk->fsize)
	{
		if (n > stk->fs[i])
			return (0);
		n = stk->fs[i];
	}
	return (1);
}

/*__________________________________________________________________________________*/
/* 									src #3											*/
/*__________________________________________________________________________________*/

int	swapper(t_stack	*stk, char *ins)
{
	int	top;
	int	bot;
	int tmp;

	if (ins[1] == 'a' || ins[1] == 's')
	{
		if ((stk->fsize - stk->bsize) < 2)
			return (error);					//erreur : nb valeur dans stack a < 2 , swap impossible
		top = stk->bsize;
		bot = top + 1;
	}
	else
	{
		if (stk->bsize < 2)
			return (error);					//erreur : nb valeur dans stack b < 2 , swap impossible
		top = stk->bsize - 1;
		bot = top - 1;
	}
	tmp = stk->fs[bot];
	stk->fs[bot] = stk->fs[top];
	stk->fs[top] = tmp;
	if (ins[1] == 's')
	{
		ins[1] = 'b';
		return (swapper(stk, ins));
	}
	return (1);	
}

int	pusher(t_stack *stk, char *ins)
{
	if (ins[1] == 'a')
	{
		if ((stk->bsize + 1) > stk->fsize)
			return (error);					//erreur : plus de valeur dans a, push impossible
		stk->bsize++;
	}
	else
	{
		if (!stk->bsize)
			return (error);					//erreur : plus de valeur dans b, push impossible
		stk->bsize--;
	}
	return (1);
}

int	rotationer(t_stack *stk, char *ins)
{
	int	dir;
	int	top;
	int	bot;
	int	tmp;

	dir = 1;
	if (ins[1] == 'r' && ins[2] != 0)
	{
		dir = -1;
		ins++;
	}
	if (ins[1] == 'a' || ins[1] == 'r')
	{
		if (dir > 0)
		{
			top = stk->bsize;
			bot = stk->fsize;
		}
		else
		{
			top = stk->fsize;
			bop = stk->bsize;
		}
	}
	else
	{
		dir *= -1;
		if (dir < 0)
		{
			top = stk->bsize - 1;
			bot = 0;
		}
		else
		{
			top = 0;
			bot = stk->bsize - 1;
		}
	}
	tmp = stk->fs[top];
	while (top != bot)
	{
		stk->fs[top] = stk->fs[top + dir];
		top += dir;
	}
	stk->fs[top] = tmp;
	if (ins[1] == 'r')
	{
		ins[1] == 'b';
		if (dir < 0)
			ins--;
		return (rotationer(stk, ins));
	}
	return (1);
}

int	instruction(t_stack *stk, char *ins)
{
	if (ins[0] = 's')
		return (swapper(stk, ins));
	if (ins[0] = 'p')
		return (pusher(stk, ins));
	if (ins[0] = 'r')
		return (rotationer(stk, ins));
	printf("Invalid Instruction\n");
	return (0);
}

/*__________________________________________________________________________________*/
/* 									src #4	(+ visual main)							*/
/*__________________________________________________________________________________*/

void	visual(t_stk *stk)
{
	int	n;
	int	i;
	char	*a;
	char	*b;

	printf("	A		B\n");
	i = 0;
	n = stk->bsize;
	if (n < (stk->fsize - n))
		n = stk->fsize - n;
	while (i < n)
	{
		if ((n - i) <= (stk->fsize - stk->bsize) > 0)
			a = ft_itoa(stk->fs[i + bsize])
		else
			a = ft_strdup(" ");
		if ((n - i) <= stk->bsize)
			b = ft_itoa(stk->fs[stk->bsize - (i + 1)]);
		else
			b = ft_strdup(" ");
		printf("	%s		%s\n", a, b);
		free(a);
		free(b);
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*stck;
	char	*ins;

	stk = NULL;
											/*add verif valeurs / erreurs*/
	stk = get_stack(stk, ac, av);
	if (!stk)
		return (error);
	while (!is_sorted(stk))
	{
		get_next_line(0, *ins);
		if (!(instruction(stk, ins))
			return (error);
		visual(stk);
	}
	printf("OK\n");
	return (0);
}