#include "libft.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (ft_is_digit(str[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
