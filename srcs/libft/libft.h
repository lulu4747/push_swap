#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

unsigned int	ft_strlen(const char *str);
int				ft_atoi(char *n);
int				ft_strcmp(char *s1, char *s2);
int				ft_is_digit(int c);
int				ft_is_number(char *str);
int				ft_atoi_secure(int *r, char *n);
int				*ft_sort(int *t, int size);
long			ft_atol(char *n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif