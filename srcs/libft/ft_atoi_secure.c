#include "libft.h"

int	ft_atoi_secure(int *r, char *n)
{
	*r = ft_atoi(n);
	if (*r != ft_atol(n))
		return (1);
	return (0);
}
