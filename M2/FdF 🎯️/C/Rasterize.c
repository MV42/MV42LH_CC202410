/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rasterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define M_PI 3.14159265358979323846
#include "../H/FdF.h"

t_point	cartesian_to_screen(t_point point)
{
	t_point	screen_point;

	screen_point.x = (W_WIDTH / 2) + point.x;
	screen_point.y = (W_HEIGHT / 2) - point.y;
	screen_point.z = point.z;
	screen_point.color = point.color;
	return (screen_point);
}

t_tab	rasterize(t_tab	*tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < tab->height)
	{
		j = 0;
		while (j < tab->width)
		{
			tab->tab[i][j].x += W_WIDTH / 2;
			tab->tab[i][j].y -= W_HEIGHT / 2;
			j++;
		}
		i++;
	}
	return (*tab);
}

t_tab	isorotate(t_tab *tab)
{
	int		i;
	int		j;
	float	temp_x;
	float	temp_y;
	float	temp_z;
	
	i = 0;
	while (i < tab->height)
	{
		j = 0;
		while (j < tab->width)
		{
			temp_x = tab->tab[i][j].x * cos(DEG45) + tab->tab[i][j].y * sin(DEG45);
			temp_y = -tab->tab[i][j].x * sin(DEG45) + tab->tab[i][j].y * cos(DEG45);
			temp_z = tab->tab[i][j].z;
			tab->tab[i][j].x = temp_x;
			tab->tab[i][j].y = temp_y * cos(MAGIC_ANGLE) - temp_z * sin(MAGIC_ANGLE);
			tab->tab[i][j].z = temp_y * sin(MAGIC_ANGLE) + temp_z * cos(MAGIC_ANGLE);
			j++;
		}
		i++;
	}
	return (*tab);
}

void	drawtabiso(t_data *img, t_tab tab)
{
	isorotate(&tab);
	rasterize(&tab);
	iter2tab(&tab, &tab, cartesian_to_screen);
	draw_grid(img, tab);
}
	checktab(tab);
