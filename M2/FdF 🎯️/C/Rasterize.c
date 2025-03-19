/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rasterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H/FdF.h"
#define M_PI 3.14159265358979323846

t_tab	rasterize(t_tab *tab)
{
    int		y;
    int		x;
    double	temp_x;
    double	temp_y;

    y = 0;
    while (y < tab->height)
    {
        x = 0;
        while (x < tab->width)
        {
            temp_x = tab->tab[x][y].x;
            temp_y = tab->tab[x][y].y;
            tab->tab[x][y].x = (temp_x - temp_y) * cos(M_PI / 6);
            tab->tab[x][y].y = (temp_x + temp_y) * sin(M_PI / 6) - tab->tab[x][y].z;
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
	static t_tablim	t = {};

	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			printf("xmin: %i xmax: %i ymin : %i ymax : %i\n", t.xmin, t.xmax, t.ymin, t.ymax);
			printf("Point at (%d, %d):\tx=%i,\ty=%i,\tcolor=%X\n",
				x, y, tab->tab[x][y].sx, tab->tab[x][y].sy, rgbtoi(tab->tab[x][y].color));
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

void	autozoom(t_tab *tab, t_tablim t)
{
    int		x;
    int		y;
    double	scale_x;
    double	scale_y;
    double	scale;
    int		offset_x;
    int		offset_y;

    // Calculate the scale factors based on the new limits
    scale_x = (W_WIDTH - 40) / (t.xmax - t.xmin);
    scale_y = (W_HEIGHT - 40) / (t.ymax - t.ymin);
    scale = fmin(scale_x, scale_y);
    // Calculate the offsets to center the points
    offset_x = 20 - t.xmin * scale;
    offset_y = 20 - t.ymin * scale;

    y = 0;
    while (y < tab->height)
    {
        x = 0;
        while (x < tab->width)
        {
            tab->tab[x][y].sx = tab->tab[x][y].x * scale + offset_x;
            tab->tab[x][y].sy = tab->tab[x][y].y * scale + offset_y;
            x++;
        }
        y++;
    }
}

void	drawtabiso(t_data *img, t_tab tab)
{
	rasterize(&tab);
	iter2tab(&tab, &tab, cartesian_to_screen);
	autozoom(&tab, getlim(&tab));
	draw_grid(img, tab);
}
