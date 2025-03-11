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

void tabvalues(t_tab *tab)
{
    int x;
    int y;
    int center_x = tab->width / 2;
    int center_y = tab->height / 2;

    y = -center_y;
    while (y < center_y)
    {
        x = -center_x;
        while (x < center_x)
        {
            (*tab).tab[x + center_x][y + center_y].x = x * 100;
            (*tab).tab[x + center_x][y + center_y].y = y * -100;
            (*tab).tab[x + center_x][y + center_y].z = 0;
            (*tab).tab[x + center_x][y + center_y].color = itorgb(0xFFFFFF);
            x++;
        }
        y++;
    }
}

void	initfaketab(t_tab *t)
{
	(*t).width = 5;
	(*t).height = 5;
	(*t).tab = allocate_tab((*t).width, (*t).height);
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
			printf("Point at (%d, %d): x=%f, y=%f, z=%f, color=%X\n",
				   x, y, tab.tab[x][y].x, tab.tab[x][y].y, tab.tab[x][y].z, rgbtoi(tab.tab[x][y].color));
			x++;
		}
		y++;
	}
}
