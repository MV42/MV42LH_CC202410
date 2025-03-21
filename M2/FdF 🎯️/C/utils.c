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

#include "../H/fdf.h"
#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

int	put_pixel(t_data *data, t_point p)
{
	char	*dst;

	if (p.sx >= 0 && p.sx < W_WIDTH && p.sy >= 0 && p.sy < W_HEIGHT)
	{
		dst = data->addr + (int)(p.sy * data->line_length + p.sx
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = rgbtoi(p.color);
		return (1);
	}
	return (0);
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

void	*ft_calloc(size_t size)
{
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

void	iter2tab(t_tab *src, t_tab *dest, t_point (*f)(t_point))
{
	int	x;
	int	y;

	y = 0;
	while (y < (*src).height)
	{
		x = 0;
		while (x < (*src).width)
		{
			(*dest).tab[x][y] = f((*src).tab[x][y]);
			x++;
		}
		y++;
	}
}

t_point	cartesian_to_screen(t_point point)
{
	point.sx += ((W_WIDTH - 1) / 2);
	point.sy += ((W_HEIGHT - 1) / 2);
	return (point);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = b;
	while (len)
		str[len--] = (unsigned char)c;
	return (b);
}

void	init(t_data *img)
{
	(*img).mlx = mlx_init();
	if (!(*img).mlx)
		return ;
	(*img).win = mlx_new_window((*img).mlx, W_WIDTH, W_HEIGHT, "FdF1");
	if (!(*img).win)
		return ;
	(*img).mlx = (*img).mlx;
	(*img).win = (*img).win;
	(*img).img = mlx_new_image((*img).mlx, W_WIDTH, W_HEIGHT);
	(*img).addr = mlx_get_data_addr((*img).img, &(*img).bits_per_pixel,
			&(*img).line_length, &(*img).endian);
}
