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

#include "../include/fdf.h"

t_tab	build_map(const char *filename)
{
	t_tab	map;

	map.lines = read_map_file(filename, &map.width, &map.height);
	if (!map.lines)
		return (map);
	map.tab = allocate_map(map.width, map.height);
	if (!map.tab)
	{
		free_map(&map);
		return (map);
	}
	fill_map(map.tab, map.lines, map.width, map.height);
	return (map);
}

t_point	**allocate_map(int width, int height)
{
	t_point		**map;
	int			x;

	x = 0;
	map = malloc(sizeof(t_point *) * width);
	if (!map)
		return (NULL);
	while (x < width)
	{
		map[x] = malloc(sizeof(t_point) * height);
		if (!map[x])
		{
			while (x-- > 0)
				free(map[x]);
			free(map);
			return (NULL);
		}
		x++;
	}
	return (map);
}

void	free_map(t_tab *map)
{
	int	i;

	if (!map)
		return ;
	if (map->lines)
		free_map_lines(map->lines, map->height);
	if (map->tab)
	{
		i = 0;
		while (i < map->height)
			free(map->tab[i++]);
		free(map->tab);
	}
	map->lines = NULL;
	map->tab = NULL;
	map->width = 0;
	map->height = 0;
}
