/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

char	init_img(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (!data->img.img_ptr)
		return (free(data->mlx), free(data->win), 0);
	data->img.px_ptr = mlx_get_data_addr(data->img.img_ptr,
		&data->img.bits_pp, &data->img.line_len, &data->img.endian);
	return (1);
}

char	init(t_data *data)
{
	data->in = (t_input){30, 0, 45, 0, 0, 0};
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "FdF1");
	if (!data->win)
		return (free(data->mlx), 0);
	init_img(data);
	return (1);
}

int main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		return (printf("Error: TOO MANY ARGS ! Need 2, Got %i.\n", argc), 1);
	if (!build_map(argv[1], &data.tab))
		return (printf("Error: File \"%s\" Couldn't Be Opened\n", argv[1]), 1);
	init(&data);
	drawtabiso(&data);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
