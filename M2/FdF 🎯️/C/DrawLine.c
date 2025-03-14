/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DrawLine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H/FdF.h"

void	bresenham(t_data *img, t_line l)
{
	int				err;
	int				sy;

	sy = (l.d.y > 0) - (l.d.y < 0);
	l.d.y = c_abs(l.d.y);
	err = l.d.x - l.d.y;
	while ((l.index.x != l.end.x || l.index.y != l.end.y)
		&& put_pixel(img, cartesian_to_screen(l.index)))
	{
		if (2 * err > -l.d.y)
		{
			err -= l.d.y;
			l.index.x++;
		}
		if (2 * err < l.d.x)
		{
			err += l.d.x;
			l.index.y += sy;
		}
		l.index.color = gradient(l);
	}
}

void	draw_line(t_data *img, t_point start, t_point end)
{
	t_line	l;
	t_rgba	temp_color;

	printf("Drawing line from (%f, %f) to (%f, %f)\n", start.x, start.y, end.x, end.y);
	l.start = start;
	l.end = end;
	if ((l.end.x - l.start.x) < 0)
	{
		temp_color = l.start.color;
		swap((void **)&l.start, (void **)&l.end);
		l.start.color = l.end.color;
		l.end.color = temp_color;
	}
	l.index = l.start;
	l.d.x = l.end.x - l.start.x;
	l.d.y = l.end.y - l.start.y;
	l.d.z = l.end.z - l.start.z;
	bresenham(img, l);
}

void	draw_grid(t_data *img, t_tab *grid)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = 0;
	while (y < grid->height)
	{
		x = 0;
		while (x < grid->width)
		{
			// p1 = grid->tab[x][y];
			ft_transform_point(grid, &grid->tab[x][y], &p1);
			if (x < grid->width - 1)
			{
				p2 = grid->tab[x + 1][y];
				// ft_transform_point(grid, &grid->tab[x + 1][y], &p2);
				draw_line(img, p1, p2);
			}
			if (y < grid->height - 1)
			{
				p2 = grid->tab[x][y + 1];
				// ft_transform_point(grid, &grid->tab[x][y + 1], &p2);
				draw_line(img, p1, p2);
			}
			x++;
		}
		y++;
	}
}
