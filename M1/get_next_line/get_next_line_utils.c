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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	total_len;

	s1_len = ft_strlen(s1) + 1;
	total_len = ft_strlen(s2) + s1_len;
	new_str = (char *)malloc(total_len * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len);
	ft_strlcat(new_str, s2, total_len);
	return (new_str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s_alloc;

	len = ft_strlen(s1) + 1;
	s_alloc = (char *)malloc(len * sizeof(char));
	if (s_alloc == NULL)
		return (NULL);
	ft_memcpy(s_alloc, s1, len);
	return (s_alloc);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == ch)
			return ((char *)s + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)s + i);
	return (NULL);
}

static char *extract_line(char **stored)
{
    char	*line;
    char	*newline_pos;
    char	*temp;

    if (!*stored)
        return (NULL);
    newline_pos = strchr(*stored, '\n');
    if (newline_pos)
    {
        *newline_pos = '\0';
        line = ft_strdup(*stored);
        temp = ft_strdup(newline_pos + 1);
        free(*stored);
        *stored = temp;
    }
    else
    {
        line = ft_strdup(*stored);
        free(*stored);
        *stored = NULL;
    }
    return (line);
}