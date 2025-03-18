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

t_tab rasterize(t_tab *tab)
{
    int i;
    int j;
    double temp_x;
    double temp_y;

    i = 0;
    while (i < tab->height)
    {
        j = 0;
        while (j < tab->width)
        {
            temp_x = tab->tab[i][j].x;
            temp_y = tab->tab[i][j].y;
            tab->tab[i][j].x = (temp_x - temp_y) * cos(M_PI / 6);
            tab->tab[i][j].y = (temp_x + temp_y) * sin(M_PI / 6) - tab->tab[i][j].z;
            tab->tab[i][j].sx = (int)tab->tab[i][j].x;
            tab->tab[i][j].sy = (int)tab->tab[i][j].y;
            j++;
        }
        i++;
    }
    return (*tab);
}

void	drawtabiso(t_data *img, t_tab tab)
{
	rasterize(&tab);
	iter2tab(&tab, &tab, cartesian_to_screen);
	draw_grid(img, tab);
}
