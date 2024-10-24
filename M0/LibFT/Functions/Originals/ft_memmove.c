/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:56:44 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:56:46 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "Bonjour je suis au Havre";
	char	dest[] = "eeeeeeeeeeeeeeeeeee";
	int		n;

	n = 23;
	printf("src : %s\n", src);
	printf("dest: %s\n", dest);
	printf("dest: %s\n", (char *)ft_memmove(dest, src, n));
	printf("src : %s\n", src);
	// printf("dest: %p\n", memmove(dest, src, n));
	return (0);
}
*/
