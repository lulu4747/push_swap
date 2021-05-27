#include "libft.h"

int	ft_atoi(char *n)
{
	int	sign;
	int	i;
	int	r;

	sign = 1;
	r = 0;
	i = 0;
	if (n[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (n[i] && !ft_is_digit(n[i]))
	{
		r = (r * 10) + (n[i] - '0');
		i++;
	}
	r = r * sign;
	return (r);
}
