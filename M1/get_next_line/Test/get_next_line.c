#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*bufs[OPEN_MAX] = {NULL};
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bufs[fd] = ft_calloc(BUFFER_SIZE + 1);
	if (bufs[fd])
		line = make_line(bufs[fd], fd);
	return (line);
}