/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H/FdF.h"

void	init(t_data *img)
{
	(*img).mlx = mlx_init();
	if (!(*img).mlx)
		return ;
	(*img).win = mlx_new_window((*img).mlx, W_WIDTH, W_HEIGHT, "FdF1");
	if (!(*img).win)
		return ;
	(*img).mlx = (*img).mlx;
	(*img).win = (*img).win;
	(*img).img = mlx_new_image((*img).mlx, W_WIDTH, W_HEIGHT);
	(*img).addr = mlx_get_data_addr((*img).img, &(*img).bits_per_pixel,
			&(*img).line_length, &(*img).endian);
}

int	main(void)
{
	t_data		img;
	t_tab		t3d;

	init(&img);
	initfaketab(&t3d);
	// checktab(t3d);
	drawtabiso(&img, t3d);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_loop(img.mlx);
}
