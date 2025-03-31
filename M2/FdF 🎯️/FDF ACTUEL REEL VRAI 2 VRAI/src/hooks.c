/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		printf("end of window\n");
		close_window(data);
		exit(0);
	}
	if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		if (key == XK_w)
			data->in.rot_x += 0.1;
		if (key == XK_a)
			data->in.rot_z -= 0.1;
		if (key == XK_s)
			data->in.rot_x -= 0.1;
		if (key == XK_d)
			data->in.rot_z += 0.1;
		init_img(data);
		printf("rot_x: %f|rot_y: %f|rot_z: %f\n", data->in.rot_x, data->in.rot_y, data->in.rot_z);
		drawtabiso(data);
	}
	return (0);
}
