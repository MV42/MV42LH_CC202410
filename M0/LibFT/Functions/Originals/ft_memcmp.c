/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:58:53 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:58:54 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((char *)s1)[i] == ((char *)s2)[i] && (int)i < (int)n - 1)
		i++;
	return (((char *)s1)[i] - ((char *)s2)[i]);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 4)
		printf("%i\n", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
}
*/
