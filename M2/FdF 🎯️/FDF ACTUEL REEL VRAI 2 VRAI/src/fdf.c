/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 15:01:03 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

void	init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
	data->win_width = W_WIDTH;
	data->win_height = W_HEIGHT;
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, "FdF1");
	if (!data->win)
	{
		free(data->mlx);
		return ;
	}
	data->img.img_ptr = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if (!data->img.img_ptr)
		return (free(data->win), free(data->mlx));
	data->img.px_ptr = mlx_get_data_addr(data->img.img_ptr,
        &data->img.bits_pp, &data->img.line_len, &data->img.endian);
}

int main(int argc, char **argv)
{
    t_data		data;
    t_tab		map;
    
    if (argc != 2)
        return (printf("Error: TOO MANY ARGS ! Need 2, Got %i.\n", argc), 1);
    map = build_map(argv[1]);
	if (!map.lines)
		return (printf("Error: File \"%s\" Couldn't Be Opened\n", argv[1]), 1);
	data.map = &map;
	init(&data);
	drawtabiso(&data, map);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
    return 0;
}
