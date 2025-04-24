/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(size);
	if (!new)
		return (NULL);
	while (i < size)
		new[i++] = '\0';
	return (new);
}

char	*ft_realloc(char *s1, size_t size)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!s1)
		return (ft_calloc(size));
	s2 = ft_calloc(size);
	if (!s2)
		return (free(s1), NULL);
	while (s1[i] && i < size - 1)
	{
		s2[i] = s1[i];
		i++;
	}
	free(s1);
	return (s2);
}

int	linelen(char *str, int *nl)
{
	nl[0] = 0;
	nl[1] = 0;
	while (str[nl[0]])
	{
		if (str[nl[0]] == '\n')
			return (nl[1] = 1, ++nl[0]);
		nl[0]++;
	}
	return (nl[0]);
}

void	cpybuf(char *line, char *buf, size_t *li)
{
	int	bj;
	int	bi;

	bj = 0;
	bi = 0;
	while (buf[bj])
	{
		if (buf[bj] == '\n')
		{
			line[(*li)++] = buf[bj++];
			break ;
		}
		line[(*li)++] = buf[bj++];
	}
	while (buf[bj])
		buf[bi++] = buf[bj++];
	while (bi < bj)
		buf[bi++] = '\0';
}
