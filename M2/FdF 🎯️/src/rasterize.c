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

void	init_pmath(t_pmath *m, t_data *data)
{
	m->cos_rx = cos(ft_degtorad(data->in.rot_x));
	m->sin_rx = sin(ft_degtorad(data->in.rot_x));
	m->cos_ry = cos(ft_degtorad(data->in.rot_y));
	m->sin_ry = sin(ft_degtorad(data->in.rot_y));
	m->cos_rz = cos(ft_degtorad(data->in.rot_z));
	m->sin_rz = sin(ft_degtorad(data->in.rot_z));
	// printf("cos_rx:%f | sin_rx:%f\n", m->cos_rx, m->sin_rx);
	// printf("cos_ry:%f | sin_ry:%f\n", m->cos_ry, m->sin_ry);
	// printf("cos_rz:%f | sin_rz:%f\n", m->cos_rz, m->sin_rz);
}

t_tab	rasterize(t_data *data)
{
	int		y;
	int		x;
	t_point	*tp;
	t_pmath	m;

	init_pmath(&m, data);
	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			tp = &data->tab.tab[x][y];
			tp->sx = (tp->x * m.cos_rz + (tp->y * m.sin_rx + tp->z * m.cos_rx)
					* m.sin_rz) * m.cos_ry
				- (tp->y * m.cos_rx - tp->z * m.sin_rx) * m.sin_ry;
			tp->sy = (tp->x * m.cos_rz + (tp->y * m.sin_rx + tp->z * m.cos_rx)
					* m.sin_rz) * m.sin_ry
				+ (tp->y * m.cos_rx - tp->z * m.sin_rx) * m.cos_ry;
			x++;
		}
		y++;
	}
	return (data->tab);
}

void	getlim(t_tab *tab)
{
	int			x;
	int			y;

	tab->lim = (t_tablim){0};
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			if (tab->tab[x][y].sx <= tab->lim.xmin)
				tab->lim.xmin = tab->tab[x][y].sx;
			if (tab->tab[x][y].sx >= tab->lim.xmax)
				tab->lim.xmax = tab->tab[x][y].sx;
			if (tab->tab[x][y].sy <= tab->lim.ymin)
				tab->lim.ymin = tab->tab[x][y].sy;
			if (tab->tab[x][y].sy >= tab->lim.ymax)
				tab->lim.ymax = tab->tab[x][y].sy;
			x++;
		}
		y++;
	}
}

void	restoretab(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			data->tab.tab[x][y].x *= 0.01;
			data->tab.tab[x][y].y *= 0.01;
			if (data->in.h_factr != 0)
				data->tab.tab[x][y].z /= data->in.h_factr;
			x++;
		}
		y++;
	}
}

void	drawtabiso(t_data *data)
{
	enlargetab(data);
	rasterize(data);
	getlim(&data->tab);
	centermap(data);
	if (data->in.zoom_bool == 1)
		autozoom(data);
	if (data->in.zoom_bool == 0)
		manualzoom(data);
	adjust_coord(data);
	draw_grid(data);
	restoretab(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
