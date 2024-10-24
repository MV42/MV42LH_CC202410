/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:55:19 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:55:21 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = 0;
}
/*
int	main(void)
{
	char str[] = "Bonjour je suis au Havre";
	int n = 20;
	printf("%s\n", str);
	ft_bzero(str, n);
	printf("%s\n", str);
	return (0);
}
*/
