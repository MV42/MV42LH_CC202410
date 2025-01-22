#include <stdlib.h>
#include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_all
{
	char	*prv[OPEN_MAX];
	char	*buf;
	ssize_t	bread;
	int		i;
	int		j;
	int		len;
}			t_gnl_vars;

char	*get_next_line(int fd)
{
	static t_gnl_vars	x;

	while (x.prv[fd] && x.prv[fd][x.len])
		++x.len;
	x.buf = malloc(x.len + BUFFER_SIZE + 1);
	x.bread = read(fd, x.buf + x.len, BUFFER_SIZE);
	if (x.bread < 0)
		return (free(x.buf), free(x.prv[fd]), x.len = 0, x.prv[fd] = NULL);
	(free(NULL), x.buf[x.len + x.bread] = 0, x.i = x.len, x.j = -1);
	while (--x.len >= 0)
		x.buf[x.len] = x.prv[fd][x.len];
	while (x.buf[++x.len] && x.buf[x.len] != '\n')
		;
	if (!x.buf[x.len] && x.bread == 0 && (free(x.buf), 1))
		return (x.buf = x.prv[fd], x.prv[fd] = NULL, x.len = 0, x.buf);
	if (!x.buf[x.len] && x.bread == BUFFER_SIZE && (free(x.prv[fd]), 1))
		return (x.prv[fd] = x.buf, x.len = 0, get_next_line(fd));
	if (!x.buf[x.len] || (x.buf[x.len] == '\n' && !x.buf[x.len + 1]))
		return (free(x.prv[fd]), x.prv[fd] = NULL, x.len = 0, x.buf);
	(free(x.prv[fd]), x.prv[fd] = malloc(sizeof(char) * (x.i + x.bread + 1)));
	if (!x.prv[fd])
		return (free(x.buf), free(x.prv[fd]), x.len = 0, x.prv[fd] = NULL);
	while (x.buf[x.len + 1 + ++x.j] || !x.prv[fd])
		x.prv[fd][x.j] = x.buf[x.len + 1 + x.j];
	return (x.prv[fd][x.j] = 0, x.buf[x.len + 1] = 0, x.len = 0, x.buf);
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd[1000];
	int		max_open;
	int		max_iter;
	char	*line;
	int		i;

	if (argc >= 4)
	{
		max_open = atoi(argv[1]);
		i = 3;
		while (max_open-- > 0 && i < argc)
		{
			fd[i] = open(argv[i], O_RDONLY);
			printf("\n📂️ %i\n", fd[i]);
			max_iter = atoi(argv[2]);
			while (max_iter-- > 0)
			{
				line = get_next_line(fd[i]);
				printf("%s↩️", line);
				free(line);
			}
			i++;
		}
	}
}
