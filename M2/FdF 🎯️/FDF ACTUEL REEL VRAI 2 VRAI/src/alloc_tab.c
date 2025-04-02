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

t_point	**allocate_map(int width, int height)
{
	t_point	**tab;
	int		x;

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

void	**ft_realloc_tab(void **ptr, size_t old_size, size_t new_size)
{
	void	**new_ptr;
	size_t	i;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
		return (free(ptr), NULL);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (i < old_size / sizeof(void *))
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}
