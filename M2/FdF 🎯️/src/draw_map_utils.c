/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	adjust_coord(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			data->tab.tab[x][y].sx += ((W_WIDTH - 1) / 2);
			data->tab.tab[x][y].sy += ((W_HEIGHT - 1) / 2);
			data->tab.tab[x][y].sx += data->in.pos_x;
			data->tab.tab[x][y].sy += data->in.pos_y;
			x++;
		}
		y++;
	}
	return (1);
}

t_tab	centermap(t_data *data)
{
	int		yoffset;
	int		xoffset;
	int		x;
	int		y;

	yoffset = (ft_abs(data->tab.lim.ymin) - ft_abs(data->tab.lim.ymax)) / 2;
	xoffset = (ft_abs(data->tab.lim.xmin) - ft_abs(data->tab.lim.xmax)) / 2;
	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			data->tab.tab[x][y].sy += yoffset;
			data->tab.tab[x][y].sx += xoffset;
			x++;
		}
		y++;
	}
	return (data->tab);
}

void	enlargetab(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			data->tab.tab[x][y].x *= 100;
			data->tab.tab[x][y].y *= 100;
			if (data->in.h_factr != 0)
				data->tab.tab[x][y].z *= data->in.h_factr;
			x++;
		}
		y++;
	}
}
