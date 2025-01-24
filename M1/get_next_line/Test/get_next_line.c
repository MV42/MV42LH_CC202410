#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl_vars	x = {0};
	char				*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!x.bufs[fd])
		x.bufs[fd] = ft_calloc(BUFFER_SIZE + 1);
	x.len = 1;
	x.res = 1;
	line = NULL;
	while (x.res)
	{
		if (!x.bufs[fd][0])
			if (read(fd, x.bufs[fd], BUFFER_SIZE) <= 0)
			{
				if (x.bufs[fd])
					free(x.bufs[fd]);
				return (NULL);
			}
		x.nl = has_nl(x.bufs[fd]);
		x.len += x.nl;
		line = ft_realloc(line, x.len);
		x.res = cpybuf(x.bufs[fd], line, &x.li);
	}
	return (line);
}
