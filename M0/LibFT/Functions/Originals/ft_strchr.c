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

char	*ft_strchr(const char *s, int c)
{
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}

#include <stdio.h>
#include <string.h>

void	main(void)
{
	printf("FT: %s\n", ft_strchr("Bonjour je suis au Havre", 'j'));
	printf("OG: %s\n", strchr("Bonjour je suis au Havre", 'j'));
}
