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

int	key_handler(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		close_window(data);
		exit(0);
	}
	rotate_key(key, data);
	translate_key(key, data);
	printf("%i\n", key);
	return (1);
}

int	rotate_key(int key, t_data *data)
{
	if (key == XK_w || key == XK_a || key == XK_s
		|| key == XK_d || key == XK_q || key == XK_e)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		if (key == XK_w && data->in.rot_x > -90)
			data->in.rot_x -= 1;
		if (key == XK_a)
			data->in.rot_z -= 1;
		if (key == XK_s && data->in.rot_x < 90)
			data->in.rot_x += 1;
		if (key == XK_d)
			data->in.rot_z += 1;
		if (key == XK_q)
			data->in.rot_y -= 1;
		if (key == XK_e)
			data->in.rot_y += 1;
		init_img(data);
		drawtabiso(data);
	}
	return (1);
}

int	translate_key(int key, t_data *data)
{
	if (key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		if (key == XK_Up)
			data->in.pos_y -= 4;
		if (key == XK_Down)
			data->in.pos_y += 4;
		if (key == XK_Right)
			data->in.pos_x += 4;
		if (key == XK_Left)
			data->in.pos_x -= 4;
		init_img(data);
		drawtabiso(data);
	}
	return (1);
}

int	mouse_handler(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	if (mousecode == 4)
		printf("Scroll UP");
	if (mousecode == 5)
		printf("Scroll DOWN");
	printf("%i", mousecode);
	return (1);
}
