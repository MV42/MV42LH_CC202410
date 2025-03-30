/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define M_PI 3.14159265358979323846

// t_tab	rasterize(t_tab *tab)
// {
// 	int		y;
// 	int		x;
// 	double	temp_x;
// 	double	temp_y;

// 	y = 0;
// 	while (y < tab->height)
// 	{
// 		x = 0;
// 		while (x < tab->width)
// 		{
// 			temp_x = tab->tab[x][y].x;
// 			temp_y = tab->tab[x][y].y;
// 			tab->tab[x][y].x = (temp_x - temp_y) * cos(ft_degtorad(0));
// 			tab->tab[x][y].y = (temp_x + temp_y) * sin(ft_degtorad(0)) - tab->tab[x][y].z;
// 			tab->tab[x][y].sx = (int)tab->tab[x][y].x;
// 			tab->tab[x][y].sy = (int)tab->tab[x][y].y;
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (*tab);
// }

t_tab	rasterize(t_tab *tab, t_input in)
{
	int		y;
	int		x;
	t_point	tmp;

	in.rot_x = 60.0;
	in.rot_z = 45.0;
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			/* Sauvegarde des coordonnées initiales */
			tmp.x = tab->tab[x][y].x;
			tmp.y = tab->tab[x][y].y;
			tmp.z = tab->tab[x][y].z;

			/* Rotation autour de l'axe X (30 degrés) */
			tab->tab[x][y].y = tmp.y * cos(ft_degtorad(in.rot_x)) 
				- tmp.z * sin(ft_degtorad(in.rot_x));
			tab->tab[x][y].z = tmp.y * sin(ft_degtorad(in.rot_x)) 
				+ tmp.z * cos(ft_degtorad(in.rot_x));

			/* Mise à jour des coordonnées temporaires après rotation X */
			tmp.y = tab->tab[x][y].y;
			tmp.z = tab->tab[x][y].z;

			/* Rotation autour de l'axe Z (45 degrés) */
			tab->tab[x][y].x = tmp.x * cos(ft_degtorad(in.rot_z)) 
				- tmp.y * sin(ft_degtorad(in.rot_z));
			tab->tab[x][y].y = tmp.x * sin(ft_degtorad(in.rot_z)) 
				+ tmp.y * cos(ft_degtorad(in.rot_z));

			/* Projection sur l'écran */
			tab->tab[x][y].sx = (int)tab->tab[x][y].x;
			tab->tab[x][y].sy = (int)tab->tab[x][y].y;
			x++;
		}
		y++;
	}
	return (*tab);
}

t_tablim	getlim(t_tab *tab)
{
	int			y;
	int			x;
	t_tablim	t;

	ft_memset(&t, 0, sizeof(t_tablim));
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			if (tab->tab[x][y].sx <= t.xmin)
				t.xmin = tab->tab[x][y].sx;
			if (tab->tab[x][y].sx >= t.xmax)
				t.xmax = tab->tab[x][y].sx;
			if (tab->tab[x][y].sy <= t.ymin)
				t.ymin = tab->tab[x][y].sy;
			if (tab->tab[x][y].sy >= t.ymax)
				t.ymax = tab->tab[x][y].sy;
			x++;
		}
		y++;
	}
	return (t);
}

void	drawtabiso(t_data *img, t_tab tab, t_input in)
{
	enlargetab(&tab);
	rasterize(&tab, in);
	centermap(&tab, getlim(&tab));
	autozoom(&tab, getlim(&tab));
	iter2tab(&tab, &tab, cartesian_to_screen);
	draw_grid(img, tab);
}

int	c_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}
