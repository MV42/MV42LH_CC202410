/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:16:44 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 12:36:35 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/Xlib.h>

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_map(data->map);
	free(data->mlx);
	exit(1);
	return (0);
}