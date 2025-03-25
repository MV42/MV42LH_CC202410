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

void	bresenham(t_data *img, t_line l)
{
	int	err;
	int	e2;
	int	sy;

	sy = (l.d.sy > 0) - (l.d.sy < 0);
	l.d.sy = c_abs(l.end.sy - l.start.sy);
	err = l.d.sx - l.d.sy;
	while (1)
	{
		if (!put_pixel(img, l.index)
			|| (l.index.sx == l.end.sx && l.index.sy == l.end.sy))
			break ;
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

void	draw_line(t_data *img, t_point start, t_point end)
{
	t_line	l;
	t_rgba	temp_color;

	l.start = start;
	l.end = end;
	if ((l.end.sx - l.start.sx) < 0)
	{
		temp_color = l.start.color;
		swap((void **)&l.start, (void **)&l.end);
		l.start.color = l.end.color;
		l.end.color = temp_color;
	}
	l.index = l.start;
	l.d.sx = l.end.sx - l.start.sx;
	l.d.sy = l.end.sy - l.start.sy;
	bresenham(img, l);
}

void	draw_grid(t_data *img, t_tab grid)
{
	int		x;
	int		y;

	y = 0;
	while (y < grid.height)
	{
		x = 0;
		while (x < grid.width)
		{
			if (x < grid.width - 1)
				draw_line(img, grid.tab[x][y], grid.tab[x + 1][y]);
			if (y < grid.height - 1)
				draw_line(img, grid.tab[x][y], grid.tab[x][y + 1]);
			x++;
		}
		y++;
	}
}
