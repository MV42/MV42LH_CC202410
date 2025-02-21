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

	color = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
	return (color);
}

int	rainbow(t_rgb c)
{
	while (c.g < c.r || c.g < c.b)
		return (c.g++, rgbtoi(c));
	while (c.r > c.g || c.r > c.b)
		return (c.r--, rgbtoi(c));
	while (c.b < c.r || c.b < c.g)
		return (c.b++, rgbtoi(c));
	while (c.g > c.r || c.g > c.b)
		return (c.g--, rgbtoi(c));
	while (c.r < c.g || c.r < c.b)
		return (c.r++, rgbtoi(c));
	while (c.b > c.r || c.b > c.g)
		return (c.b--, rgbtoi(c));
	return (rgbtoi(c));
}
