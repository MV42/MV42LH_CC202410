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

t_point	**allocate_map(int width, int height)
{
	t_point	**map;
	int		x;

	x = 0;
	map = (t_point **)ft_calloc(sizeof(t_point *) * width);
	if (!map)
		return (NULL);
	while (x < width)
	{
		map[x] = (t_point *)ft_calloc(sizeof(t_point) * height);
		if (!map[x])
		{
			while (x-- > 0)
				free(map[x]);
			free(map);
			return (NULL);
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
			(*tab).tab[x][y].y = y * 100;
			(*tab).tab[x][y].z = 0;
			(*tab).tab[x][y].color = itorgb(0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	p3dto2d(t_point *src, t_point *dest)
{
	int	scale;
	int	offset_x;
	int	offset_y;

	if (!src || !dest)
	{
		fprintf(stderr, "Error: src or dest is NULL\n");
		return;
	}

	scale = 40;
	offset_x = W_WIDTH / 2;
	offset_y = W_HEIGHT / 3;

	printf("src: x=%d, y=%d, z=%d\n", src->x, src->y, src->z);

	(*dest).x = ((*src).x - (*src).y) * cos(ISO_ANGLE_Y) * scale + offset_x;
	(*dest).y = ((*src).x + (*src).y) * sin(ISO_ANGLE_Y) - (*src).z * sin(ISO_ANGLE_X);
	(*dest).y = (*dest).y * scale + offset_y;
	(*dest).z = (*src).z;
	(*dest).s = (*src).s;
	(*dest).color = (*src).color;

	printf("dest: x=%d, y=%d, z=%d\n", dest->x, dest->y, dest->z);
}

void	iter2tab(t_tab *src, t_tab *dest, void (*f)(t_point*, t_point*))
{
	int	x;
	int	y;

	y = 0;
	while (y < (*src).height)
	{
		x = 0;
		while (x < (*src).width)
		{
			f(&(*src).tab[x][y], &(*dest).tab[x][y]);
			x++;
		}
		y++;
	}
}

void	initfaketab(t_tab *t)
{
	(*t).width = 4;
	(*t).height = 4;
	(*t).tab = allocate_map((*t).width, (*t).height);
	tabvalues(t);
}

void	checktab(t_tab tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < tab.height)
	{
		x = 0;
		while (x < tab.width)
		{
			printf("Point at (%d, %d): x=%d, y=%d, z=%d, color=%X\n",
				   x, y, tab.tab[x][y].x, tab.tab[x][y].y, tab.tab[x][y].z, rgbtoi(tab.tab[x][y].color));
			x++;
		}
		y++;
	}
}

void	free_tab(t_tab *t)
{
	int		x;

	while (x < (*t).width)
	{
		free(*(*t).tab);
		x++;
	}
	free((*t).tab);
}

int	main(void)
{
	t_data		img;
	t_tab		t3d;
	t_tab		t2d;

	init(&img);
	initfaketab(&t2d);
	checktab(t2d);
	link_points(&img, t2d);
	//iter2tab(&t3d, &t2d, p3dto2d);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_hook(img.win, 17, 0, free_tab, &t2d);
	mlx_loop(img.mlx);
}
