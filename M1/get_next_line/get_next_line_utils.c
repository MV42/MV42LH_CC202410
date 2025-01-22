#include "get_next_line.h"

void	*ft_calloc(size_t number)
{
	size_t	*new;
	size_t	aligned_size;
	size_t	i;

	i = 0;
	aligned_size = ((number + 3) & ~3);
	new = malloc(aligned_size);
	if (new)
	{
		while (i < aligned_size / sizeof(size_t))
		{
			if (i < aligned_size / sizeof(size_t))
				new[i++] = 0;
			else
				break ;
		}
	}
	return (new);
}

char	*ft_realloc(char *s1, size_t size)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!s1)
	{
		s1 = ft_calloc(size);
		return (s1);
	}
	s2 = ft_calloc(size);
	if (!s2)
		return (NULL);
	while (s1[i] && i < size - 1)
	{
		s2[i] = s1[i];
		i++;
	}
	free(s1);
	return (s2);
}

int	has_nl(char *buf)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
			return (i + 1);
		if (!buf[i])
			return (i);
		i++;
	}
	return (BUFFER_SIZE);
}

void	ft_strlcat(char *buf, char **line, size_t *li, size_t len)
{
	size_t	bi;

	bi = 0;
	while (*li < len - 1)
		(*line)[(*li)++] = buf[bi++];
}

void	clean_buf(char **buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((*buf)[j])
	{
		if ((*buf)[j++] == '\n')
			while ((*buf)[j])
				(*buf)[i++] = (*buf)[j++];
		if (!(*buf)[j])
			while (i < j)
				(*buf)[i++] = '\0';
	}
}
