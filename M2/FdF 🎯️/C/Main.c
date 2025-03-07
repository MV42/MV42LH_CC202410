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

void	init_point(t_point src, t_point *dest)
{
	(*dest).x = src.x;
	(*dest).y = src.y;
	(*dest).z = src.z;
	(*dest).s = src.s;
	(*dest).color = src.color;
}

t_point **allocate_map(int width, int height)
{
    t_point **map;
    int x;

    x = 0;
    map = malloc(sizeof(t_point *) * width);
    if (!map)
        return (NULL);
    while (x < width)
    {
        map[x] = malloc(sizeof(t_point) * height);
        if (!map[x])
        {
            while (x-- > 0)
                free(map[x]);
            free(map);
            return(NULL);
        }
        x++;
    }
    return (map);
}

void	tabvalues(t_tab *tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*tab).height)
	{
		x = 0;
		while (x < (*tab).width)
		{
			(*tab).tab[x][y].x = x * 100;
			x++;
		}
		(*tab).tab[x-1][y].x = y * 100;
		y++;
	}
}

int	main(void)
{
	t_data		img;
	t_tab		tab;

	init(&img);
	tab.width = 5;
	tab.height = 3;
	tab.tab = allocate_map(tab.width, tab.height);
	tabvalues(&tab);
	link_points(&img, tab);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_loop(img.mlx);
}

// int	main(int ac, char **av)
// {
// 	t_data		img;
// 	t_point		start;
// 	t_point		end;

// 	if (ac != 7)
// 		return (0);
// 	init(&img);
// 	init_point((t_point){atoi(av[1]), atoi(av[2]),
// 		atoi(av[3]), 0, itorgb(0x00FF00)}, &start);
// 	init_point((t_point){atoi(av[4]), atoi(av[5]),
// 		atoi(av[6]), 0, itorgb(0xFF00FF)}, &end);
// 	draw_line(&img, start, end);
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	mlx_key_hook(img.win, key_hook, &img);
// 	mlx_hook(img.win, 17, 0, close_window, &img);
// 	mlx_loop(img.mlx);
// }
