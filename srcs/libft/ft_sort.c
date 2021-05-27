#include "libft.h"

int	*ft_sort(int *t, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (t[i] > t[i + 1])
		{
			tmp = t[i];
			t[i] = t[i + 1];
			t[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (t);
}