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

void	ft_matrix_identity(t_matrix4x4 *m)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		m->data[i] = 0;
		i++;
	}
	m->data[0] = 1;
	m->data[5] = 1;
	m->data[10] = 1;
	m->data[15] = 1;
}

void ft_setup_isometric_view(t_matrix4x4 *m)
{
    const float angle = 2.094395102; // 120° en radians
    const float cos_val = cos(angle);
    const float sin_val = sin(angle);
    
    ft_matrix_identity(m);
    
    // Première ligne : transformation X
    m->data[0] = cos_val;
    m->data[1] = sin_val;
    m->data[2] = 0;
    
    // Deuxième ligne : transformation Y
    m->data[4] = -sin_val / 2;
    m->data[5] = cos_val / 2;
    m->data[6] = sqrt(3) / 2;
    
    // Troisième ligne : z reste inchangé
    m->data[8] = 0;
    m->data[9] = 0;
    m->data[10] = 0;
}

void	ft_transform_point(t_point *src, t_point *dest)
{
	t_matrix4x4	m;

	ft_setup_isometric_view(&m);
	dest->x = src->x * m.data[0] + src->y * m.data[4] + src->z * m.data[8];
	dest->y = src->x * m.data[1] + src->y * m.data[5] + src->z * m.data[9];
	dest->z = src->x * m.data[2] + src->y * m.data[6] + src->z * m.data[10];
	dest->color = src->color;
}
