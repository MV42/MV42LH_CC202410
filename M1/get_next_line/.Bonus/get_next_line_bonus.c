/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl_vars	x;

	while (x.prv[fd] && x.prv[fd][x.len])
		++x.len;
	x.buf = malloc(x.len + BUFFER_SIZE + 1);
	x.bread = read(fd, x.buf + x.len, BUFFER_SIZE);
	if (x.bread < 0)
	{
		free(x.buf);
		free(x.prv[fd]);
		x.len = 0;
		return (x.prv[fd] = NULL);
	}
	free(NULL);
	x.buf[x.len + x.bread] = 0;
	x.i = x.len;
	x.j = -1;
	while (--x.len >= 0)
		x.buf[x.len] = x.prv[fd][x.len];
	while (x.buf[++x.len] && x.buf[x.len] != '\n')
		;
	if (!x.buf[x.len] && !x.bread && (free(x.buf), 1))
	{
		x.buf = x.prv[fd];
		x.prv[fd] = NULL;
		x.len = 0;
		return (x.buf);
	}
	if (!x.buf[x.len] && x.bread == BUFFER_SIZE && (free(x.prv[fd]), 1))
	{
		x.prv[fd] = x.buf;
		x.len = 0;
		return (get_next_line(fd));
	}
	if (!x.buf[x.len] || (x.buf[x.len] == '\n' && !x.buf[x.len + 1]))
	{
		free(x.prv[fd]);
		x.prv[fd] = NULL;
		x.len = 0;
		return (x.buf);
	}
	free(x.prv[fd]);
	x.prv[fd] = malloc(sizeof(char) * (x.i + x.bread + 1));
	if (!x.prv[fd])
	{
		free(x.buf);
		free(x.prv[fd]);
		x.len = 0;
		x.prv[fd] = NULL;
		return (x.prv[fd]);
	}
	while (x.buf[x.len + 1 + ++x.j] || !x.prv[fd])
		x.prv[fd][x.j] = x.buf[x.len + 1 + x.j];
	x.prv[fd][x.j] = 0;
	x.buf[x.len + 1] = 0;
	x.len = 0;
	return (x.buf);
}
