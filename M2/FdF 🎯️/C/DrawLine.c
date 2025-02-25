#include "../H/FdF.h"

void	my_mlx_pixel_put(t_data *data, t_point p)
{
	char	*dst;

	dst = data->addr + (p.y * data->line_length + p.x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = p.color;
}

void	swap(void **ptr1, void **ptr2)
{
	void *tmp;

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

int gradient(t_point start, t_point end, t_point d)
{
    int	len;

	len = d.y;
	if (d.s > -1 && d.s < 1)
		len = d.x;
	start.color += (((end.color >> 16) - (start.color >> 16)) / len) << 16;
	start.color += (((end.color >> 8) - (start.color >> 8)) / len) << 8;
	start.color += (end.color - start.color) / len;
	return (start.color);
}
// Fix graident
void	bresenham(t_data *img, t_point start, t_point end, t_point d)
{
	int	err;
	int	sy;

	sy = (d.y > 0) - (d.y < 0);
	d.y = c_abs(d.y);
	err = d.x - d.y;
	while (start.x != end.x || start.y != end.y)
	{
		my_mlx_pixel_put(img, start);
		if (2 * err > -d.y)
		{
			err -= d.y;
			start.x ++;
		}
		if (2 * err < d.x)
		{
			err += d.x;
			start.y += sy;
		}
		start.color = gradient(start, end, d);
	}
	my_mlx_pixel_put(img, start);
}

void	draw_line(t_data *img, t_point start, t_point end)
{
	t_point	d;

	if ((end.x - start.x) < 0)
		swap((void **)&start, (void **)&end);
	d.x = end.x - start.x;
	d.y = end.y - start.y;
	d.z = end.z - start.z;
	d.s = 0;
	if (d.x && d.y)
		d.s = (float)d.y / d.x;
	bresenham(img, start, end, d);
}
