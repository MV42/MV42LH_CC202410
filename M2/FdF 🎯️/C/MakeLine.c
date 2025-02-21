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

void	bresenham_v(t_data *img, t_point start,
			t_point end, t_point d)
{
    int	p;

    p = 2 * d.x - d.y;
    while(start.x < end.x)
    {
        if(p >= 0)
        {
            my_mlx_pixel_put(img, start);
            start.y++;
            p += 2 * d.y - 2 * d.x;
        }
        else
        {
            my_mlx_pixel_put(img, start);
            p += 2 * d.y;
        }
        start.x++;
    }
}

void	bresenham_h(t_data *img, t_point start,
			t_point end, t_point d)
{
    int	p;

    p = 2 * d.y - d.x;
    while(start.x < end.x)
    {
        if(p >= 0)
        {
            my_mlx_pixel_put(img, start);
            start.y++;
            p += 2 * d.y - 2 * d.x;
        }
        else
        {
            my_mlx_pixel_put(img, start);
            p += 2 * d.y;
        }
        start.x++;
    }
}

void	draw_line(t_data *img, t_point start, t_point end)
{
	t_point	d;

	if (start.x > end.x)
		swap_points(&start, &end);
	d.x = abs(end.x - start.x);
	d.y = abs(end.y - start.y);
	if (d.x < d.y)
		bresenham_v(img, start, end, d);
	else
		bresenham_h(img, start, end, d);
}
