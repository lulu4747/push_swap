#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * ft_strlen(str));
	if (!ret)
		return (NULL);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}
