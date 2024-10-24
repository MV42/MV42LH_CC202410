/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:28:18 by mavander          #+#    #+#             */
/*   Updated: 2024/10/17 17:28:19 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = (char)c;
	return (s);
}
/*
int	main(void)
{
	char str[] = "Bonjour je suis au Havre";
	char c = 'H';
	int n = 20;
	printf("%s\n", str);
	ft_memset(str, c, n);
	// memset(str, c, n);
	printf("%s\n", str);
	return (0);
}
*/
