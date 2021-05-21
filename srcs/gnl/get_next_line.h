#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 80

typedef struct		s_gnl
{
	int				fd;
	int				n;
	char			*buf;
}					t_gnl;

size_t				ft_slen(const char *ptr);
int					ft_istrchr(char *src, char c);
char				*ft_strjoinfree(char *start, char *end, int f);
char				*ft_strccpy(char *start, char c);
int					get_next_line(int fd, char **line);
int					readline(t_gnl *ptr, int fd, char **line);
t_gnl				*nw(int fd);

#endif
