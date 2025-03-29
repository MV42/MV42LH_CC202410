/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	put_pixel(t_data *data, t_point p)
{
	char	*dst;

	if (p.sx >= 0 && p.sx < W_WIDTH && p.sy >= 0 && p.sy < W_HEIGHT)
	{
		dst = data->img.px_ptr + (int)(p.sy * data->img.line_len + p.sx
				* (data->img.bits_pp / 8));
		*(unsigned int *)dst = rgbtoi(p.color);
		return (1);
	}
	return (0);
}
