#include "get_next_line.h"

char	*ft_calloc(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(size);
	if (new)
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
		return (NULL);
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
			nl[1] = 1;
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
		line[(*li)++] = buf[bj++];
		if (buf[bj] == '\n')
		{
			line[(*li)++] = buf[bj++];
			break ;
		}
	}
	while (buf[bj])
		buf[bi++] = buf[bj++];
	while (bi < bj)
		buf[bi++] = '\0';
}

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
				return (line);
		}
		llen += linelen(buf, nl);
		line = ft_realloc(line, llen);
		cpybuf(line, buf, &li);
		if (nl[1])
			return (line);
	}
}