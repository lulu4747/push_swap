#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_strlen(char *str);
int	ft_atoi(char *n);
int	ft_strcmp(char *s1, char *s2);
int ft_is_digit(int c);
int	ft_is_number(char *str);
long	ft_atol(char *n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif