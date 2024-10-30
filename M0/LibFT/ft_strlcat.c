/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:18 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:57:19 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	t;

	i = 0;
	while (dest[i])
		i++;
	t = i;
	i = 0;
	if (t > size)
		t = size;
	while (t + i < size - 1 && size && src[i])
	{
		dest[t + i] = src[i];
		i++;
	}
	if (size > t)
		dest[t + i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (t + i);
}
