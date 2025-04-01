/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_data *data, t_line l)
{
	int	err;
	int	e2;
	int	sy;

	sy = (l.d.sy > 0) - (l.d.sy < 0);
	l.d.sy *= (l.d.sy > 0) - (l.d.sy < 0);
	err = l.d.sx - l.d.sy;
	while (1)
	{
		if (l.index.sx == l.end.sx && l.index.sy == l.end.sy)
			break ;
		put_pixel(data, l.index);
		e2 = err;
		if (e2 > -l.d.sx)
		{
			err -= l.d.sy;
			l.index.sx++;
		}
		if (e2 < l.d.sy)
		{
			err += l.d.sx;
			l.index.sy += sy;
		}
		l.index.color = gradient(l);
	}
}

void	draw_line(t_data *data, t_point start, t_point end)
{
	t_line	l;
	t_point	tmp;

	l.start = start;
	l.end = end;
	if (l.start.sx > l.end.sx)
	{
		tmp = l.start;
		l.start = l.end;
		l.end = tmp;
		l.end.color = l.start.color;
		l.start.color = tmp.color;
	}
	l.index = l.start;
	l.d.sx = l.end.sx - l.start.sx;
	l.d.sy = l.end.sy - l.start.sy;
	bresenham(data, l);
}

void	draw_grid(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			if (x < data->tab.width - 1)
				draw_line(data, data->tab.tab[x][y], data->tab.tab[x + 1][y]);
			if (y < data->tab.height - 1)
				draw_line(data, data->tab.tab[x][y], data->tab.tab[x][y + 1]);
			x++;
		}
		y++;
	}
}
