/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define M_PI 3.14159265358979323846

t_tab	rasterize(t_data *win)
{
	int		y;
	int		x;

	y = 0;
	while (y < win->tab.height)
	{
		x = 0;
		while (x < win->tab.width)
		{
			win->tab.tab[x][y].sx = (win->tab.tab[x][y].x * cos(ft_degtorad(win->in.rot_y)) + (win->tab.tab[x][y].y * sin(ft_degtorad(win->in.rot_x)) + win->tab.tab[x][y].z * cos(ft_degtorad(win->in.rot_x))) * sin(ft_degtorad(win->in.rot_y))) * cos(ft_degtorad(win->in.rot_z)) - (win->tab.tab[x][y].y * cos(ft_degtorad(win->in.rot_x)) - win->tab.tab[x][y].z * sin(ft_degtorad(win->in.rot_x))) * sin(ft_degtorad(win->in.rot_z));
			win->tab.tab[x][y].sy = (win->tab.tab[x][y].x * cos(ft_degtorad(win->in.rot_y)) + (win->tab.tab[x][y].y * sin(ft_degtorad(win->in.rot_x)) + win->tab.tab[x][y].z * cos(ft_degtorad(win->in.rot_x))) * sin(ft_degtorad(win->in.rot_y))) * sin(ft_degtorad(win->in.rot_z)) + (win->tab.tab[x][y].y * cos(ft_degtorad(win->in.rot_x)) - win->tab.tab[x][y].z * sin(ft_degtorad(win->in.rot_x))) * cos(ft_degtorad(win->in.rot_z));
			x++;
		}
		y++;
	}
	return (win->tab);
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

void	drawtabiso(t_data *data)
{
	enlargetab(&data->tab);
	rasterize(data);
	centermap(&data->tab, getlim(&data->tab));
	autozoom(&data->tab, getlim(&data->tab));
	iter2tab(&data->tab, &data->tab, cartesian_to_screen);
	draw_grid(data, data->tab);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}

int	c_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}
