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

void	getscale(t_data *data)
{
	while (data->tab.lim.xmax * data->in.zoom < (W_WIDTH / 2) - 20
		&& data->tab.lim.ymax * data->in.zoom < (W_HEIGHT / 2) - 20
		&& data->tab.lim.xmin * data->in.zoom < (W_WIDTH / 2) - 20
		&& data->tab.lim.ymin * data->in.zoom < (W_HEIGHT / 2) - 20
		&& data->tab.lim.xmax * data->in.zoom > (-W_WIDTH / 2) + 20
		&& data->tab.lim.ymax * data->in.zoom > (-W_HEIGHT / 2) + 20
		&& data->tab.lim.xmin * data->in.zoom > (-W_WIDTH / 2) + 20
		&& data->tab.lim.ymin * data->in.zoom > (-W_HEIGHT / 2) + 20)
		data->in.zoom += 0.000001;
}

void	autozoom(t_data *data)
{
	int		x;
	int		y;

	data->in.zoom = 0;
	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			getscale(data);
			data->tab.tab[x][y].sx *= data->in.zoom;
			data->tab.tab[x][y].sy *= data->in.zoom;
			x++;
		}
		y++;
	}
}

void	manualzoom(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			data->tab.tab[x][y].sx *= data->in.zoom;
			data->tab.tab[x][y].sy *= data->in.zoom;
			x++;
		}
		y++;
	}
}
