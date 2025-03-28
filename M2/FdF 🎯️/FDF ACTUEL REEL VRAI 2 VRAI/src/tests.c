/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:41:01 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 15:35:01 by ngaudoui         ###   ########.fr       */
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
