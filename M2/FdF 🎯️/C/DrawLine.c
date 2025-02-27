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

void	my_mlx_pixel_put(t_data *data, t_point p)
{
	char	*dst;

	dst = data->addr + (p.y * data->line_length + p.x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = rgbtoi(p.color);
}

void	swap(void **ptr1, void **ptr2)
{
	void	*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

int	c_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

void	bresenham(t_data *img, t_line l)
{
	int				err;
	int				sy;

	sy = (l.d.y > 0) - (l.d.y < 0);
	l.d.y = c_abs(l.d.y);
	err = l.d.x - l.d.y;
	while ((l.index.x != l.end.x || l.index.y != l.end.y)
		&& (my_mlx_pixel_put(img, l.index), 1))
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

	l.start = start;
	l.end = end;
	if ((l.end.x - l.start.x) < 0)
	{
		swap((void **)&l.start, (void **)&l.end);
		l.index.color = l.start.color;
		l.start.color = l.end.color;
		l.end.color = l.index.color;
	}
	l.index = l.start;
	l.d.x = l.end.x - l.start.x;
	l.d.y = l.end.y - l.start.y;
	l.d.z = l.end.z - l.start.z;
	l.d.s = 0;
	if (l.d.x && l.d.y)
		l.d.s = (float)l.d.y / l.d.x;
	printf("Ouais");
	bresenham(img, l);
}
