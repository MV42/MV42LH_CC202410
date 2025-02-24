/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                              :+:      :+:    :+:   */
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
	*(unsigned int *)dst = p.color;
}

void	swap_points(t_point *a, t_point *b)
{
	t_point	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bresenham(t_data *img, t_point start,
			t_point end, t_point d)
{
	int	error;
	int	step;

	step = 1;
	if (d.y < 0)
		step = -1;
	d.y = abs(d.y);
	error = d.x / 2;
	while (start.x <= end.x)
	{
		my_mlx_pixel_put(img, start);
		error -= d.y;
		if (error < 0)
		{
			start.y += step;
			error += d.x;
		}
		start.x++;
	}
}

void	draw_line(t_data *img, t_point start, t_point end)
{
	t_point	d;

	d.x = end.x - start.x;
	d.y = end.y - start.y;
	d.z = end.z - start.z;
	d.s = 0;
	if (d.x && d.y)
		d.s = (float)d.y / d.x;
	if (d.x < 0)
		swap_points(&start, &end);
	bresenham(img, start, end, d);
}
