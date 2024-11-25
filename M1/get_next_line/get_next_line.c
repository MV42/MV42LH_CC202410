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

char    *get_next_line(int fd)
{
	char    *line;
	char    *buf;
	int     i;
	int     ret;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = 0;
	buf = malloc(2);
	if (!buf)
		return (NULL);
	buf[1] = 0;
	while ((ret = read(fd, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
			break ;
		i = 0;
		while (line[i])
			i++;
		line = realloc(line, i + 2);
		if (!line)
			return (NULL);
		line[i] = buf[0];
		line[i + 1] = 0;
	}
	free(buf);
	if (ret == 0)
		return (NULL);
	return (line);
}
