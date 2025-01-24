#include "get_next_line.h"

void	*ft_calloc(size_t number)
{
	char	*new;
	size_t	aligned_size;
	size_t	i;

	i = 0;
	aligned_size = ((number + 3) & ~3);
	new = malloc(aligned_size);
	if (new)
		while (i < aligned_size)
			new[i++] = 0;
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

int	cpybuf(char *buf, char *line, size_t *li)
{
	int	bj;
	int	bi;
	int	res;

	bj = 0;
	bi = 0;
	res = 1;
	while (buf[bj])
	{
		line[(*li)++] = buf[bj++];
		if (buf[bj - 1] == '\n')
		{
			res = 0;
			while (buf[bj])
				buf[bi++] = buf[bj++];
		}
		if (!buf[bj])
			while (bi < bj)
				buf[bi++] = '\0';
	}
	return (res);
}
