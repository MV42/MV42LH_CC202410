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

#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define M_PI 3.14159265358979323846
#include "../H/FdF.h"

t_matrix	ft_init_transform_matrix(t_tab *grid)
{
	t_matrix	matrix;
	float		scale;
	float		max_dim;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix.m[i][j] = 0;
			j++;
		}
		i++;
	}
	matrix.m[0][0] = 0.866;
	matrix.m[0][1] = 0.5;
	matrix.m[0][2] = 0;
	matrix.m[1][0] = -0.354;
	matrix.m[1][1] = 0.612;
	matrix.m[1][2] = 0.707;
	matrix.m[2][0] = 0.354;
	matrix.m[2][1] = -0.612;
	matrix.m[2][2] = 0.707;
	matrix.m[0][3] = W_WIDTH / 2;
	matrix.m[1][3] = W_HEIGHT / 2;
	matrix.m[2][3] = 0;
	max_dim = grid->width > grid->height ? grid->width : grid->height;
	scale = (W_WIDTH < W_HEIGHT ? W_WIDTH : W_HEIGHT) * 0.8 / max_dim;
	matrix.m[0][0] *= scale;
	matrix.m[0][1] *= scale;
	matrix.m[1][0] *= scale;
	matrix.m[1][1] *= scale;
	matrix.m[1][2] *= scale;
	matrix.m[2][0] *= scale;
	matrix.m[2][1] *= scale;
	matrix.m[2][2] *= scale;
	matrix.m[3][3] = 1;
	return (matrix);
}

// void	ft_transform_point(t_tab *grid, t_point *src, t_point *dst)
// {
// 	static t_matrix	matrix;
// 	static int		initialized = 0;
	
// 	if (!initialized)
// 	{
// 		matrix = ft_init_transform_matrix(grid);
// 		initialized = 1;
// 	}
// 	dst->x = matrix.m[0][0] * src->x + matrix.m[0][1] * src->y 
// 		+ matrix.m[0][2] * src->z + matrix.m[0][3];
// 	dst->y = matrix.m[1][0] * src->x + matrix.m[1][1] * src->y 
// 		+ matrix.m[1][2] * src->z + matrix.m[1][3];
// 	dst->z = matrix.m[2][0] * src->x + matrix.m[2][1] * src->y 
// 		+ matrix.m[2][2] * src->z + matrix.m[2][3];
// 	dst->color = src->color;
// }

t_point	ft_transform_point(t_point point)
{
	t_point	result;
	float	cos_z;
	float	sin_z;
	float	cos_x;
	float	sin_x;
	float	temp_x;
	float	temp_y;

	cos_z = cos(DEG45);
	sin_z = sin(DEG45);
	cos_x = cos(MAGIC_ANGLE);
	sin_x = sin(MAGIC_ANGLE);

	/* Rotation sur l'axe Z (sens horaire = négatif en math) */
	temp_x = point.x * cos_z + point.y * sin_z;
	temp_y = -point.x * sin_z + point.y * cos_z;

	/* Inclinaison sur l'axe X */
	result.x = temp_x;
	result.y = temp_y * cos_x - point.z * sin_x;
	result.z = temp_y * sin_x + point.z * cos_x;
	result.color = point.color;

	return (result);
}
