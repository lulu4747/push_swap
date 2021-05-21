#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char *ptr;

	if (!(ptr = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}