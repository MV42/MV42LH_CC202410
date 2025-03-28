/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:16:12 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 15:09:59 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iter2tab(t_tab *src, t_tab *dest, t_point (*f)(t_point))
{
	int	x;
	int	y;

	y = 0;
	while (y < (*src).height)
	{
		x = 0;
		while (x < (*src).width)
		{
			(*dest).tab[x][y] = f((*src).tab[x][y]);
			x++;
		}
		y++;
	}
}

t_point	cartesian_to_screen(t_point point)
{
	point.sx += ((W_WIDTH - 1) / 2);
	point.sy += ((W_HEIGHT - 1) / 2);
	return (point);
}

void	autozoom(t_tab *tab, t_tablim t)
{
	int		x;
	int		y;

	tab->scale = 0;
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			while (t.xmax * tab->scale < (W_WIDTH / 2) - 20 && t.ymax
				* tab->scale < (W_HEIGHT / 2) - 20)
				tab->scale += 0.000001;
			tab->tab[x][y].sx *= tab->scale;
			tab->tab[x][y].sy *= tab->scale;
			x++;
		}
		y++;
	}
}

t_tab	centermap(t_tab *tab, t_tablim t)
{
	int		yoffset;
	int		xoffset;
	int		x;
	int		y;

	yoffset = (c_abs(t.ymin) - c_abs(t.ymax)) / 2;
	xoffset = (c_abs(t.xmin) - c_abs(t.xmax)) / 2;
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			tab->tab[x][y].sy += yoffset;
			tab->tab[x][y].sx += xoffset;
			x++;
		}
		y++;
	}
	return (*tab);
}

void	enlargetab(t_tab *tab)
{
	int		x;
	int		y;

	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			tab->tab[x][y].x *= 100;
			tab->tab[x][y].y *= 100;
			tab->tab[x][y].z *= 70;
			x++;
		}
		y++;
	}
}
