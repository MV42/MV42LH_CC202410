/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:58 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:58:00 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (i >= 0 && s[i] != c)
		i--;
	s = s + i;
	return ((char *)s++);
}
/*
int	main(void)
{
	printf("FT: %s\n", ft_strrchr("Bonjour je suis auj HavrE", 'j'));
	printf("OG: %s\n", strrchr("Bonjour je suis auj HavrE", 'j'));
}
*/
