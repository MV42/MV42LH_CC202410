/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:38 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:57:39 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("OG: %i\n", strncmp(argv[1], argv[2], atoi(argv[3])));
		printf("FT: %i\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
*/
