#include "libft.h"

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
