/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:15:32 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 08:10:47 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief Calculates the length of a string.
//
// @param str The input string.
// @return The length of the string.
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// @brief Writes a string to a file descriptor.
//
// @param s The string to write.
// @param fd The file descriptor.
void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
		write(fd, s++, 1);
}
