/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_rgb	itorgb(unsigned int color)
{
	t_rgb	rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}

int	rgbtoi(t_rgb rgb)
{
	int	color;

	color = ((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b;
	return (color);
}

t_rgb	gradient(t_line l)
{
	int		len;

	if (l.d.sx > l.d.sy)
		len = l.d.sx;
	else
		len = c_abs(l.d.sy);
	l.index.color.r += (l.end.color.r - l.start.color.r) / len;
	l.index.color.g += (l.end.color.g - l.start.color.g) / len;
	l.index.color.b += (l.end.color.b - l.start.color.b) / len;
	return (l.index.color);
}

int	gethighlow(t_data *data, t_line *l)
{
	int		x;
	int		y;

	l->start.z = MIN_FLOAT;
	l->end.z = MAX_FLOAT;
	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			if (data->tab.tab[x][y].z <= l->start.z)
				l->start = data->tab.tab[x][y];
			if (data->tab.tab[x][y].z >= l->end.z)
				l->end = data->tab.tab[x][y];
			x++;
		}
		y++;
	}
	return (1);
}

int	colorheight(int key, t_data *data)
{
	int		x;
	int		y;
	t_line	l;

	if (key == XK_c)
	{
		l = (t_line){0};
		gethighlow(data, &l);
		y = 0;
		while (y < data->tab.height)
		{
			x = 0;
			while (x < data->tab.width)
			{
				l.index = data->tab.tab[x][y];
				data->tab.tab[x][y].color = gradient(l);
				x++;
			}
			y++;
		}
	}
	return (1);
}
