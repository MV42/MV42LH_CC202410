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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(char *str, char c)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] != c)
		i--;
	str = str + i;
	return (str++);
}
/*
#include <stdio.h>
#include <string.h>

void	main(void)
{
	printf("FT: %s\n", ft_strrchr("Bonjour je suis auj HavrE", 'j'));
	printf("OG: %s\n", strrchr("Bonjour je suis auj HavrE", 'j'));
}
*/
