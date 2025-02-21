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

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_winsize	win;

	win.x = 1000;
	win.y = 500;
	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, win.x, win.y, "FdF1");
	if (!mlx_win)
		return (1);
	img.mlx = mlx;
	img.win = mlx_win;
	img.img = mlx_new_image(mlx, win.x, win.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_line(&img, (t_point){0, 0, 0, 0xFFFFFF},
		(t_point){10, 100, 0, 0xFFFFFF});
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, &img);
	mlx_hook(mlx_win, 17, 0, close_window, &img);
	mlx_loop(mlx);
	return (0);
}
