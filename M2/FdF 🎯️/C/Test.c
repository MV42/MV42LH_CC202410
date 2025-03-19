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

void	tabvalues(t_tab *tab)
{
	int		x;
	int		y;
	float	center_x;
	float	center_y;

	center_x = (tab->width - 1) / 2.0;
	center_y = (tab->height - 1) / 2.0;
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			tab->tab[x][y].x = (x - center_x);
			tab->tab[x][y].y = (center_y - y);
			tab->tab[x][y].z = 0;
			if (x % 2)
				tab->tab[x][y].z = 75;
			tab->tab[x][y].color = itorgb(0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	initfaketab(t_tab *t)
{
	(*t).width = 3;
	(*t).height = 3;
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
			printf("Point at (%d, %d):\tx=%f,\ty=%f,\tz=%f,\tcolor=%X\n",
				x, y, tab.tab[x][y].x, tab.tab[x][y].y,
				tab.tab[x][y].z, rgbtoi(tab.tab[x][y].color));
			x++;
		}
		y++;
	}
}
