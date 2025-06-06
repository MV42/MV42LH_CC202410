/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_columns(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		if (!ft_isspace(line[i]) && line[i] != '\n')
			count++;
		while (line[i] && line[i] != ' ')
			i++;
	}
	return (count);
}

char	read_map_file(t_tab *tab, const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: Invalid FD\n"), 0);
	line = get_next_line(fd);
	while (line)
	{
		if (tab->height == 0)
			tab->width = count_columns(line);
		if (!add_line_to_map(&tab->lines, line, tab->height))
			return (close(fd), free(line),
				free_map_lines(tab->lines, tab->height), 0);
		tab->height++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (1);
}

int	add_line_to_map(char ***lines, char *line, int height)
{
	char	**temp;

	temp = (char **)ft_realloc_tab((void **)*lines,
			height * sizeof(char *), (height + 1) * sizeof(char *));
	if (!temp)
	{
		free(line);
		free_map_lines(*lines, height);
		return (0);
	}
	*lines = temp;
	(*lines)[height] = line;
	return (1);
}

void	free_map_lines(char **lines, int height)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (i < height)
		free(lines[i++]);
	free(lines);
}
