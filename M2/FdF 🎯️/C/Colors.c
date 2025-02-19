/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assistant <assistant@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:00:00 by assistant         #+#    #+#             */
/*   Updated: 2025/02/19 10:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	ft_get_rgb_component(double temp1, double temp2, double temp3)
{
	if (temp3 < 0.0)
		temp3 += 1.0;
	if (temp3 > 1.0)
		temp3 -= 1.0;
	if (6.0 * temp3 < 1.0)
		return (temp1 + (temp2 - temp1) * 6.0 * temp3);
	if (2.0 * temp3 < 1.0)
		return (temp2);
	if (3.0 * temp3 < 2.0)
		return (temp1 + (temp2 - temp1) * (0.666 - temp3) * 6.0);
	return (temp1);
}

unsigned int	ft_hsl(int h, int s, int l)
{
	double	temp1;
	double	temp2;
	double	rgb[3];
	double	hsl[3];

	hsl[0] = (double)h / 360.0;
	hsl[1] = (double)s / 100.0;
	hsl[2] = (double)l / 100.0;
	if (s == 0)
		rgb[0] = rgb[1] = rgb[2] = l * 2.55;
	else
	{
		temp2 = (hsl[2] < 0.5) ? hsl[2] * (1.0 + hsl[1]) 
			: hsl[2] + hsl[1] - hsl[2] * hsl[1];
		temp1 = 2.0 * hsl[2] - temp2;
		rgb[0] = ft_get_rgb_component(temp1, temp2, hsl[0] + 0.333);
		rgb[1] = ft_get_rgb_component(temp1, temp2, hsl[0]);
		rgb[2] = ft_get_rgb_component(temp1, temp2, hsl[0] - 0.333);
	}
	return ((unsigned int)((int)(rgb[0] * 255) << 16) | 
		((int)(rgb[1] * 255) << 8) | (int)(rgb[2] * 255));
}
