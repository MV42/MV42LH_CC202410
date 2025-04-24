/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	build_tab(const char *filename, t_tab *tab)
{
	*tab = (t_tab){NULL, NULL, 0, 0, (t_tablim){0}, (t_mat4){0}};
	if (!read_map_file(tab, filename))
		return (ft_printf("Error: Couldn't Read Map File\n"), 0);
	tab->tab = allocate_map(tab->width, tab->height);
	if (!tab->tab)
	{
		free_map(tab);
		free_map_lines(tab->lines, tab->height);
		return (ft_printf("Error: Couldn't Allocate Map\n"), 0);
	}
	fill_map(tab->tab, tab->lines, tab->width, tab->height);
	free_map_lines(tab->lines, tab->height);
	return (1);
}
