/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:24 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:57:26 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	x;
	unsigned int	i;

	i = 0;
	while (((char *)src)[i] != '\0')
		i++;
	x = i;
	i = 0;
	if (size != 0)
	{
		while (((char *)src)[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (x);
}
/*
int	main(void)
{
	char			dst[] = "AAAAAAAAAAAAAAAAAAAA";
	char			*src = "Bonjour je suis au Havre";
	unsigned int	size = 5;

	printf("%i\n", (int)ft_strlcpy(dst, src, size));
	printf("%s\n", src);
	printf("%s\n", dst);
}
*/
