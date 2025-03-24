/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H/fdf.h"

void	fill_map(t_point **map, char **lines, int width, int height)
{
	int		x;
	int		y;
	char	**split_line;

	y = 0;
	while (y < height)
	{
		x = 0;
		split_line = ft_split(lines[y], ' ');
		while (x < width)
		{
			map[y][x]
				= extract_point(split_line[x], x - width / 2, y - height / 2);
			x++;
		}
		free_split(split_line);
		y++;
	}
}

t_point	extract_point(char *value, int x, int y)
{
	t_point		point;
	char		*z_value;
	char		*color;

	point.color = itorgb(0);
	z_value = extract_z_value(value);
	color = extract_color(value);
	if (!z_value || !color)
	{
		free(z_value);
		free(color);
		return ((t_point){0, 0, 0, itorgb(0), 0, 0});
	}
	if (color[0] != '\0')
		point = (t_point){x, y, ft_atoi(z_value),
			itorgb(ft_atoi_base(color, "0123456789ABCDEF")), 0, 0};
	else
		point = (t_point){x, y, ft_atoi(z_value), itorgb(0xFFFFFF), 0, 0};
	free(z_value);
	free(color);
	return (point);
}

char	*extract_color(char *value)
{
	int		i;
	int		j;
	char	*color;

	i = 0;
	j = 0;
	color = ft_calloc(ft_strlen(value) + 1);
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
	z_value = ft_calloc(ft_strlen(value) + 1);
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
