/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map(t_point **tab, char **lines, int width, int height)
{
	int		x;
	int		y;
	int		ix;
	int		iy;
	char	**split_line;

	y = 0;
	iy = height / 2 - height;
	while (y < height)
	{
		ix = width / 2 - width;
		x = 0;
		split_line = ft_split(lines[y], ' ');
		iy++;
		while (x < width)
		{
			tab[x][y] = extract_point(split_line[x], ++ix, iy);
			x++;
		}
		free_split(split_line);
		y++;
	}
}

t_point	extract_point(char *value, int x, int y)
{
	t_point	point;
	char		*z_value;
	char		*color;

	point.color = itorgb(0xFFFFFF);
	z_value = extract_z_value(value);
	color = extract_color(value);
	if (!z_value || !color)
	{
		free(z_value);
		free(color);
		return ((t_point){0, 0, 0, itorgb(0), 0, 0});
	}
	point = (t_point){x, y, ft_atoi(z_value), point.color, 0, 0};
	if (color[0])
		point.color = itorgb(ft_atoi_base(color, "0123456789ABCDEF"));
	return (free(z_value), free(color), point);
}

char	*extract_color(char *value)
{
	int		i;
	int		j;
	char	*color;

	i = 0;
	j = 0;
	color = ft_calloc(ft_strlen(value) + 1, sizeof(char));
	if (!color)
		return (NULL);
	while (value[i] && value[i] != ',')
		i++;
	if (value[i] == ',')
		i += 3;
	while (value[i])
	{
		color[j++] = value[i++];
	}
	color[j] = '\0';
	return (color);
}

char	*extract_z_value(char *value)
{
	int		i;
	char	*z_value;

	i = 0;
	z_value = ft_calloc(strlen(value) + 1, sizeof(char));
	if (!z_value)
		return (NULL);
	while (value[i] && value[i] != ',')
	{
		z_value[i] = value[i];
		i++;
	}
	z_value[i] = '\0';
	return (z_value);
}

void	free_split(char **split_line)
{
	int	x;

	x = 0;
	while (split_line[x])
		free(split_line[x++]);
	free(split_line);
}
