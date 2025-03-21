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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_pn_b(long long n, char *base)
{
	uintmax_t	nbr;
	uintmax_t	base_length;
	int			len;

	len = 0;
	base_length = ft_strlen(base);
	if (n < 0)
	{
		len += write(1, "-", 1);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= base_length)
		len += ft_pn_b(nbr / base_length, base);
	len += write(1, &base[nbr % base_length], 1);
	return (len);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int			len;
	uintmax_t	nbr;
	uintmax_t	base_length;
	char		*base;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	base = "0123456789abcdef";
	base_length = 16;
	nbr = ptr;
	if (nbr >= base_length)
		len += ft_pn_b(nbr / base_length, base);
	len += write(1, &base[nbr % base_length], 1);
	return (len);
}
