/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additionnal.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	if (!n)
		return ;
	i = 0;
	str = s;
	while (i < n)
		*(str + i++) = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	alloc = malloc(count * size);
	if (alloc == NULL)
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_split(char **result, int words)
{
	while (words >= 0)
		free(result[words--]);
	free(result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		words;
	int		i;
	char	*start;

	result = ft_calloc((words = count_words(s, c)) + 1, sizeof(char *));
	if (!s || !result)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			result[i] = ft_substr(start, 0, s - start);
			if (!result[i++])
				return (free_split(result, i - 1), NULL);
		}
		else
			s++;
	}
	return (result);
}
