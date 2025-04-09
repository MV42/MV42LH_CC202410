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
	data->in.zoom = 0;
	while (data->tab.lim.xmax * data->in.zoom < (W_WIDTH / 2) - 20
		&& data->tab.lim.ymax * data->in.zoom < (W_HEIGHT / 2) - 20
		&& data->tab.lim.xmin * data->in.zoom < (W_WIDTH / 2) - 20
		&& data->tab.lim.ymin * data->in.zoom < (W_HEIGHT / 2) - 20
		&& data->tab.lim.xmax * data->in.zoom > (-W_WIDTH / 2) + 20
		&& data->tab.lim.ymax * data->in.zoom > (-W_HEIGHT / 2) + 20
		&& data->tab.lim.xmin * data->in.zoom > (-W_WIDTH / 2) + 20
		&& data->tab.lim.ymin * data->in.zoom > (-W_HEIGHT / 2) + 20)
		data->in.zoom += 1.0 / (data->tab.lim.xmax * data->tab.lim.ymax);
}

void	mapzoom(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	if (data->in.zoom_bool == 1)
		getscale(data);
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
