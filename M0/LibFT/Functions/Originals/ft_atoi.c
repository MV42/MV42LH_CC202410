/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:54:36 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:54:40 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb *= 10;
		nb += *nptr - 48;
		nptr++;
	}
	return (nb * sign);
}

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("FT: %i\n", ft_atoi("   -3456g543"));
	printf("OG: %i\n", atoi("   -3456g543"));
}
