/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:51 by mavander          #+#    #+#             */
/*   Updated: 2024/10/14 15:57:52 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((char *)big[i] && (char *)big[i] != (char *)little[j])
	{
		while ((char *)big[i] == (char *)little[j])
		{
			if (little[j] == '\0')
				return (big)
		}
		big++;
	}
		i++;
}
