/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	offset;
	int		src_i;

	dst_len = ft_strlen(dst);
	offset = dst_len;
	src_i = 0;
	if (dstsize < dst_len + 1)
		return (ft_strlen(src) + dstsize);
	if (dstsize > dst_len + 1)
	{
		while (*(src + src_i) && offset < dstsize - 1)
			*(dst + offset++) = *(src + src_i++);
		*(dst + offset) = '\0';
	}
	return (dst_len + ft_strlen(src));
}
