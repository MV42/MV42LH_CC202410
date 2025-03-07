/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H/FdF.h"

int	put_pixel(t_data *data, t_point p)
{
	char	*dst;

	if (p.x >= 0 && p.x <= W_WIDTH && p.y >= 0 && p.y <= W_HEIGHT)
	{
		dst = data->addr + (p.y * data->line_length + p.x * (data->bits_per_pixel / 8));
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

t_point	to2d(t_point src, int a)
{
	t_point	dst;
	dst.x = src.x * cos(a) + src.y * cos(a+2) + src.z * cos(a-2);
	dst.y = src.x * sin(a) + src.y * sin(a+2) + src.z * sin(a-2);
	return (dst);
}

void	link_points(t_data *img, t_tab tab)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < tab.width && y < tab.height)
	{
		if (x+1 < tab.width)
			draw_line(img, tab.tab[x][y], tab.tab[x+1][y]);
		if (y+1 < tab.height)
			draw_line(img, tab.tab[x][y], tab.tab[x][y+1]);
		x++;
		y++;
	}
}
