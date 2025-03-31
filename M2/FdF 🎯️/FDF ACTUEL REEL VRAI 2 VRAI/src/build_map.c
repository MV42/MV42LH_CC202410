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

char	build_map(const char *filename, t_tab *tab)
{
	*tab = (t_tab){NULL, NULL, 0, 0, 0};
	if (!read_map_file(tab, filename))
		return (ft_printf("Error: ReadMapFile\n"), 0);
	tab->tab = allocate_map(tab->width, tab->height);
	if (!tab->tab)
	{
		free_map(tab);
		free_map_lines(tab->lines, tab->height);
		return (ft_printf("Error: AllocateMap\n"), 0);
	}
	fill_map(tab->tab, tab->lines, tab->width, tab->height);
	free_map_lines(tab->lines, tab->height);
	return (ft_printf("Success: BuildMap\n"), 1);
}

t_point	**allocate_map(int width, int height)
{
	t_point	**tab;
	int			x;

	if (width <= 0 || height <= 0)
		return (NULL);
	x = 0;
	tab = malloc(sizeof(t_point *) * width);
	if (!tab)
		return (NULL);
	while (x < width)
	{
		tab[x] = malloc(sizeof(t_point) * height);
		if (!tab[x])
		{
			while (x > 0)
			{
				free(tab[--x]);
			}
			free(tab);
			return (NULL);
		}
		x++;
	}
	return (tab);
}

void	free_map(t_tab *tab)
{
	int	i;
	if (!tab)
		return ;
	if (tab->tab)
	{
		i = 0;
		while (i < tab->width)
		{
			free(tab->tab[i]);
			i++;
		}
		free(tab->tab);
	}
	tab->lines = NULL;
	tab->tab = NULL;
	tab->width = 0;
	tab->height = 0;
}
