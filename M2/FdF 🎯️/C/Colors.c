/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H/FdF.h"

t_rgba	itorgb(unsigned int color)
{
	t_rgba	rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}

int	rgbtoi(t_rgba rgb)
{
	int	color;

	color = ((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b;
	return (color);
}

t_rgba	gradient(t_line l)
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
