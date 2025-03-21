/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_all
{
	size_t	li;
	size_t	llen;
	char	*line;
	int		readb;
	int		nl[2];
}	t_gnl_vars;

// get_next_line_utils.c
char	*ft_calloc(size_t size);
char	*ft_realloc(char *s1, size_t size);
int		linelen(char *str, int *nl);
void	cpybuf(char *line, char *buf, size_t *li);

// get_next_line.c
char	*make_line(char *buf, int fd, char **buff);
char	*get_next_line(int fd);

#endif
