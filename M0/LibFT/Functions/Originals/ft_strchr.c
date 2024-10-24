/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:00 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:57:02 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
/*
int	main(void)
{
	printf("FT: %s\n", ft_strchr("Bonjour je suis au Havre", 'j'));
	printf("OG: %s\n", strchr("Bonjour je suis au Havre", 'j'));
}
*/
