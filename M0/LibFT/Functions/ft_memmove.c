/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:56:44 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:56:46 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memmove(unsigned char *dest, const unsigned char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && dest[i] && src[i])
	{
		dest[i] = src[i];
		src[i] = 0;
		i++;
	}
}
