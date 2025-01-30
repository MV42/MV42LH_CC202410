/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_line(char *buf, int fd, char **buff)
{
	t_gnl_vars	x;

	x.li = 0;
	x.llen = 1;
	x.line = NULL;
	while (1)
	{
		while (*buf)
		{
			x.llen += linelen(buf, x.nl);
			x.line = ft_realloc(x.line, x.llen);
			if (!x.line)
				return (free(buf), *buff = NULL, NULL);
			cpybuf(x.line, buf, &x.li);
			if (x.nl[1])
				return (x.line);
		}
		x.readb = read(fd, buf, BUFFER_SIZE);
		if (x.readb == 0 && x.line && x.line[0])
			return (free(buf), *buff = NULL, x.line);
		if (x.readb <= 0)
			return (free(buf), free(x.line), *buff = NULL, NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*bufs[OPEN_MAX] = {NULL};

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!bufs[fd])
		bufs[fd] = ft_calloc(BUFFER_SIZE + 1);
	if (bufs[fd])
		return (make_line(bufs[fd], fd, &(bufs[fd])));
	return (NULL);
}
