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

void	initfaketab(t_tab *t)
{
	(*t).width = 4;
	(*t).height = 4;
	(*t).tab = allocate_tab((*t).width, (*t).height);
	tabvalues(t);
}
