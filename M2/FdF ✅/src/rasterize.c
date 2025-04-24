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

void	init_matrix(t_data *data, t_mat4 *m)
{
	t_pmath	c;

	c.cos_rx = cos(ft_degtorad(data->in.rot_x));
	c.sin_rx = sin(ft_degtorad(data->in.rot_x));
	c.cos_ry = cos(ft_degtorad(data->in.rot_y));
	c.sin_ry = sin(ft_degtorad(data->in.rot_y));
	c.cos_rz = cos(ft_degtorad(data->in.rot_z));
	c.sin_rz = sin(ft_degtorad(data->in.rot_z));
	m->m[0][0] = c.cos_ry * c.cos_rz;
	m->m[0][1] = -c.cos_ry * c.sin_rz;
	m->m[0][2] = c.sin_ry;
	m->m[1][0] = c.sin_rx * c.sin_ry * c.cos_rz + c.cos_rx * c.sin_rz;
	m->m[1][1] = -c.sin_rx * c.sin_ry * c.sin_rz + c.cos_rx * c.cos_rz;
	m->m[1][2] = -c.sin_rx * c.cos_ry;
	m->m[2][0] = -c.cos_rx * c.sin_ry * c.cos_rz + c.sin_rx * c.sin_rz;
	m->m[2][1] = c.cos_rx * c.sin_ry * c.sin_rz + c.sin_rx * c.cos_rz;
	m->m[2][2] = c.cos_rx * c.cos_ry;
	m->m[0][3] = 0;
	m->m[1][3] = 0;
	m->m[2][3] = 0;
	m->m[3][3] = 1.0f;
}

void	apply_mat4(t_point *p, t_mat4 *m)
{
	p->sx = p->x * m->m[0][0] + p->y * m->m[0][1] + p->z * m->m[0][2];
	p->sy = p->x * m->m[1][0] + p->y * m->m[1][1] + p->z * m->m[1][2];
}

t_tab	rasterize(t_data *data)
{
	int		y;
	int		x;

	init_matrix(data, &data->tab.mtrx);
	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
			apply_mat4(&data->tab.tab[x++][y], &data->tab.mtrx);
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

void	drawtabiso(t_data *data)
{
	enlargetab(data);
	rasterize(data);
	getlim(&data->tab);
	centermap(data);
	mapzoom(data);
	adjust_coord(data);
	draw_grid(data);
	restoretab(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
