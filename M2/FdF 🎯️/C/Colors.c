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

	color = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
	return (color);
}

int	rainbow(t_rgba c)
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
