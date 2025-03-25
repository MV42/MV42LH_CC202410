/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// int	main(void)
// {
// 	t_data		img;
// 	t_tab		t3d;

// 	init(&img);
// 	initfaketab(&t3d);
// 	drawtabiso(&img, t3d);
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	mlx_key_hook(img.win, key_hook, &img);
// 	mlx_hook(img.win, 17, 0, close_window, &img);
// 	mlx_loop(img.mlx);
// }
// Main Nathan
int	main(int argc, char **argv)
{
	t_tab	map;

	if (argc != 2)
	{
		printf("Usage: %s <fichier_map.fdf>\n", argv[0]);
		return (1);
	}
	map = build_map(argv[1]);
	free_map(&map);
	return (0);
}
