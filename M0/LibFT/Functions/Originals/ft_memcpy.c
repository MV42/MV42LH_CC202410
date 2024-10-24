/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:56:31 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:56:33 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((const char *)src + i);
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "Bonjour je suis au Havre";
	char	dest[] = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
	int		n = 23;

	printf("src : %s\n", src);
	printf("dest: %s\n", dest);
	printf("dest: %s\n", ft_memcpy(dest, src, n));
	// printf("dest: %s\n", memcpy(dest, src, n));
	return (0);
}
*/
