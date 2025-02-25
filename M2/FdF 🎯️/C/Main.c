/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H/FdF.h"

int	main(int ac, char **av)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;

	if (ac != 5)
		return (0);
	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "FdF1");
	if (!mlx_win)
		return (1);
	img.mlx = mlx;
	img.win = mlx_win;
	img.img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_line(&img, (t_point){atoi(av[1]), atoi(av[2]), 0, 0xFF0000, 0},
		(t_point){atoi(av[3]), atoi(av[4]), 0, 0x0000FF, 0});
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, &img);
	mlx_hook(mlx_win, 17, 0, close_window, &img);
	mlx_loop(mlx);
	return (0);
}
