/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char *buf, int fd)
{
	size_t	li;
	size_t	llen;
	char	*line;
	int		readb;
	int		nl[2];

	li = 0;
	llen = 1;
	line = NULL;
	while (1)
	{
		if (!*buf)
		{
			readb = read(fd, buf, BUFFER_SIZE);
			if (readb <= 0)
				return (ft_free(buf));
		}
		llen += linelen(buf, nl);
		line = ft_realloc(line, llen);
		cpybuf(line, buf, &li);
		if (nl[1])
			return (line);
	}
}

char	*get_next_line(int fd)
{
	static char	*bufs[OPEN_MAX] = {NULL};
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (line);
	if (!bufs[fd])
		bufs[fd] = ft_calloc(BUFFER_SIZE + 1);
	if (bufs[fd])
		line = make_line(bufs[fd], fd);
	return (line);
}
