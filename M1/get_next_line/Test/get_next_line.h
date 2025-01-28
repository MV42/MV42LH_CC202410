#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

char	*ft_calloc(size_t size);
char	*ft_realloc(char *s1, size_t size);
int		linelen(char *str, int *nl);
void	cpybuf(char *line, char *buf, size_t *li);
char	*make_line(char *buf, int fd);

#endif
