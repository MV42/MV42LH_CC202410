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
#define M_PI 3.14159265358979323846

t_tab	rasterize(t_tab *tab)
{
	int		y;
	int		x;
	double	temp_x;
	double	temp_y;

	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			temp_x = tab->tab[x][y].x;
			temp_y = tab->tab[x][y].y;
			tab->tab[x][y].x = (temp_x - temp_y) * cos(M_PI / 6);
			tab->tab[x][y].y = (temp_x + temp_y) * sin(M_PI / 6)
				- tab->tab[x][y].z;
			tab->tab[x][y].sx = (int)tab->tab[x][y].x;
			tab->tab[x][y].sy = (int)tab->tab[x][y].y;
			x++;
		}
		y++;
	}
	return (*tab);
}

t_tablim	getlim(t_tab *tab)
{
	int			y;
	int			x;
	t_tablim	t;

	ft_memset(&t, 0, sizeof(t_tablim));
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			if (tab->tab[x][y].sx <= t.xmin)
				t.xmin = tab->tab[x][y].sx;
			if (tab->tab[x][y].sx >= t.xmax)
				t.xmax = tab->tab[x][y].sx;
			if (tab->tab[x][y].sy <= t.ymin)
				t.ymin = tab->tab[x][y].sy;
			if (tab->tab[x][y].sy >= t.ymax)
				t.ymax = tab->tab[x][y].sy;
			x++;
		}
		y++;
	}
	return (t);
}

void	autozoom(t_tab *tab, t_tablim t)
{
	int		x;
	int		y;

	tab->scale = 0;
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			while (t.xmax * tab->scale < (W_WIDTH / 2) - 20 && t.ymax
				* tab->scale < (W_HEIGHT / 2) - 20)
				tab->scale += 0.000001;
			tab->tab[x][y].sx *= tab->scale;
			tab->tab[x][y].sy *= tab->scale;
			x++;
		}
		y++;
	}
}

t_tab	centermap(t_tab *tab, t_tablim t)
{
	int		yoffset;
	int		xoffset;
	int		x;
	int		y;

	yoffset = (c_abs(t.ymin) - c_abs(t.ymax)) / 2;
	xoffset = (c_abs(t.xmin) - c_abs(t.xmax)) / 2;
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			tab->tab[x][y].sy += yoffset;
			tab->tab[x][y].sx += xoffset;
			x++;
		}
		y++;
	}
	return (*tab);
}

void	enlargetab(t_tab *tab)
{
	int		x;
	int		y;

	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			tab->tab[x][y].x *= 100;
			tab->tab[x][y].y *= 100;
			tab->tab[x][y].z *= 100;
			x++;
		}
		y++;
	}
}

void	drawtabiso(t_data *img, t_tab tab)
{
	enlargetab(&tab);
	rasterize(&tab);
	centermap(&tab, getlim(&tab));
	autozoom(&tab, getlim(&tab));
	iter2tab(&tab, &tab, cartesian_to_screen);
	draw_grid(img, tab);
}
