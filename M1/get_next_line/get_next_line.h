#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>
# include <fcntl.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

void	*ft_calloc(size_t number);
char	*ft_realloc(char *s1, size_t size);
int		has_nl(char *buf);
void	ft_strlcat(char *buf, char **line, size_t *li, size_t len);
void	clean_buf(char **buf);

typedef struct s_all
{
	char	*bufs[OPEN_MAX];	// Buffers
	int		readb;				// Bytes read from read()
	size_t	bi;					// Buffer Index
	size_t	li;					// Line Index
	size_t	nl;
	size_t	len;
}				t_gnl_vars;
#endif
