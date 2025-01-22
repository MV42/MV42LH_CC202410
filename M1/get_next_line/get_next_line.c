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
	line = 0;
	x.nl = BUFFER_SIZE;
	while (x.nl == BUFFER_SIZE)
	{
		if (!x.bufs[fd][0])
			x.readb = read(fd, x.bufs[fd], BUFFER_SIZE);
		if (x.readb <= 0)
			break ;
		x.nl = has_nl(x.bufs[fd]);
		x.len += x.nl;
		line = ft_realloc(line, x.len);
		ft_strlcat(x.bufs[fd], &line, &x.li, x.len);
		clean_buf(&x.bufs[fd]);
	}
	return (line);
}
