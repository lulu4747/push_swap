/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:44:15 by lfourage          #+#    #+#             */
/*   Updated: 2021/05/31 12:44:49 by lfourage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*nealloc(char **ptr, int size_supp)
{
	int		strl;
	char	*tptr;

	strl = 0;
	if ((*ptr) != NULL)
		strl = ft_strlen(*ptr);
	tptr = (char *)malloc(sizeof(char) * (strl + size_supp));
	if (!tptr)
		return (0);
	if (*ptr && *(*ptr))
	{
		while (*(*ptr))
			*tptr++ = *((*ptr)++);
		*tptr = 0;
	}
	free(*ptr - strl);
	*ptr = tptr - strl;
	return (*ptr);
}

static int	err(char **line, int *ret, int rv)
{
	free(*line);
	*line = 0;
	*ret = rv;
	return (rv);
}

int	get_next_line(char **line, int *ret)
{
	int	llen;

	*ret = 1;
	llen = -1;
	*line = 0;
	while (!(*line) || (*line)[llen])
	{
		llen += *ret;
		if (*ret == -1 || !nealloc(line, 2))
			return (err(line, ret, -1));
		*ret = read(0, *line + llen, 1);
		*(*line + llen + 1) = 0;
		if (!*ret || (*line)[llen] == '\n')
			(*line)[llen] = 0;
	}
	*ret = (llen || *ret);
	if (!*ret)
		return (err(line, ret, *ret));
	return (1);
}
