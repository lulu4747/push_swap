#include "libft.h"

int	ft_atoi(char *n)
{
	int	size;
	int	i;
	int	r;

	r = 0;
	i = 0;
	size = ft_strlen(n) - 1;
	while (i <= size)
	{
		r = (r * 10) + (n[i] - '0');
		i++;
	}
	return (r);
}
