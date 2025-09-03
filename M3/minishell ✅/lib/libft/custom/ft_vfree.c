/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2025/08/12 21:14:13 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

// Free multiple pointers at once
// Usage: ft_vfree(n, &p1, &p2, &p3, ...);
// Needs the count of pointers to free
// Each arg has to be a void**
// Set pointer to NULL after free to avoid dangling pointers.
void	ft_vfree(int count, ...)
{
	va_list	args;
	int		i;
	void	**pp;

	if (count <= 0)
		return ;
	va_start(args, count);
	i = 0;
	while (i < count)
	{
		pp = va_arg(args, void **);
		if (pp && *pp)
		{
			free(*pp);
			*pp = NULL;
		}
		i++;
	}
	va_end(args);
}
