/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_pn_b(va_arg(args, int), "0123456789");
	else if (format == 'u')
		len += ft_pn_b(va_arg(args, unsigned int), "0123456789");
	else if (format == 'x')
		len += ft_pn_b(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_pn_b(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		len += ft_printpct();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;	

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_formats(args, format[i++ + 1]);
		else
			len += write(1, &format[i++], 1);
	}
	va_end(args);
	return (len);
}
