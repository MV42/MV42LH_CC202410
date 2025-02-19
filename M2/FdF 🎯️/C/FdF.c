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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_line(t_data *img, t_point start, t_point end, int color)
{
    int dx;
    int dy;
    int	p;

    dx = end.x - start.x;
    dy = end.y - start.y;
    p = 2 * dy - dx;
    while(start.x < end.x)
    {
        if(p >= 0)
        {
            my_mlx_pixel_put(img, start.x, start.y, rainbow(&color));
            start.y++;
            p += 2 * dy - 2 * dx;
        }
        else
        {
            my_mlx_pixel_put(img, start.x, start.y, rainbow(&color));
            p += 2 * dy;
        }
        start.x++;
    }
}

int	main(void)
{
    void		*mlx;
    void		*mlx_win;
    t_data		img;
	t_inputs	in;

	in.win_x = 1000;
	in.win_y = 500;
    mlx = mlx_init();
    if (!mlx)
        return (1);
    mlx_win = mlx_new_window(mlx, in.win_x, in.win_y, "FdF");
    if (!mlx_win)
        return (1);

    img.mlx = mlx;
    img.win = mlx_win;
	img.img = mlx_new_image(mlx, in.win_x, in.win_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);

	make_line(&img, (t_point){0, 0}, (t_point){1000, 50}, 0x000000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

    mlx_key_hook(mlx_win, key_hook, &img);
    mlx_hook(mlx_win, 17, 0, close_window, &img);
    mlx_loop(mlx);
    return (0);
}
