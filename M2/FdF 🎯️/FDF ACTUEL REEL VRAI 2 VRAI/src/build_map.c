/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tab	build_map(const char *filename)
{
	t_tab	map;

	map = (t_tab){NULL, NULL, 0, 0, 0};
	read_map_file(&map, filename);
	if (!map.lines)
		return (map);
	map.tab = allocate_map(map.width, map.height);
	if (!map.tab)
	{
		free_map(&map);
		free_map_lines(map.lines, map.height);
		return (map);
	}
	fill_map(map.tab, map.lines, map.width, map.height);
	free_map_lines(map.lines, map.height);
	return (map);
}

t_point	**allocate_map(int width, int height)
{
	t_point	**map;
	int			x;

	if (width <= 0 || height <= 0)
		return (NULL);
	x = 0;
	map = malloc(sizeof(t_point *) * width);
	if (!map)
		return (NULL);
	while (x < width)
	{
		map[x] = malloc(sizeof(t_point) * height);
		if (!map[x])
		{
			while (x > 0)
			{
				free(map[--x]);
			}
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
	if (map->tab)
	{
		i = 0;
		while (i < map->width)
		{
			free(map->tab[i]);
			i++;
		}
		free(map->tab);
	}
	map->lines = NULL;
	map->tab = NULL;
	map->width = 0;
	map->height = 0;
}
