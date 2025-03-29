/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			printf("Point at (%d, %d):\tx=%f,\ty=%f,\tz=%f,\tcolor=%X,\tsx=%i,\tsy=%i\n",
				x, y, tab.tab[x][y].x, tab.tab[x][y].y,
				tab.tab[x][y].z, rgbtoi(tab.tab[x][y].color),
				tab.tab[x][y].sx, tab.tab[x][y].sy);
			x++;
		}
		y++;
	}
	printf("\n");
}
