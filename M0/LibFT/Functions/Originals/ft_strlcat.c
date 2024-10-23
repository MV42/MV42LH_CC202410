/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:18 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:57:19 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	t;

	i = 0;
	t = (unsigned int)ft_strlen(dest);
	if (t > size)
		t = size;
	while (t + i < size - 1 && size && src[i])
	{
		dest[t + i] = src[i];
		i ++;
	}
	if (size > t)
		dest[t + i] = '\0';
	i = (unsigned int)ft_strlen(src);
	return (t + i);
}
