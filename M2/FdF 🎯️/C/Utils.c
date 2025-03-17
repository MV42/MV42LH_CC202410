/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H/FdF.h"

int	put_pixel(t_data *data, t_point p)
{
    char	*dst;

    if (p.x >= 0 && p.x < W_WIDTH && p.y >= 0 && p.y < W_HEIGHT)
    {
        dst = data->addr + (int)(p.y * data->line_length + p.x * (data->bits_per_pixel / 8));
        *(unsigned int *)dst = rgbtoi(p.color);
        return (1);
    }
    return (0);
}

void	swap(void **ptr1, void **ptr2)
{
	void	*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

int	c_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

void	*ft_calloc(size_t size)
{
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

void	iter2tab(t_tab *src, t_tab *dest, t_point (*f)(t_point))
{
	int	x;
	int	y;

	y = 0;
	while (y < (*src).height)
	{
		x = 0;
		while (x < (*src).width)
		{
			(*dest).tab[x][y] = f((*src).tab[x][y]);
			x++;
		}
		y++;
	}
}
