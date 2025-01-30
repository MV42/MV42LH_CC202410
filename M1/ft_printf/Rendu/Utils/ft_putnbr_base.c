/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int					len;
	size_t				len_base;
	unsigned long long	nbrr;

	len = 0;
	nbrr = nbr;
	len_base = ft_strlen(base);
	if (nbrr < len_base)
	{
		write(1, &base[nbrr % len_base], 1);
		len++;
	}
	else
	{
		len += ft_putnbr_base(nbrr / len_base, base);
		len += ft_putnbr_base(nbrr % len_base, base);
	}
	return (len);
}
