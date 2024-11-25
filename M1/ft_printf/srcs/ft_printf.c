/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char specifier, va_list args, t_flags *flags)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int), flags));
	if (specifier == 's')
		return (ft_print_str(va_arg(args, char *), flags));
	if (specifier == 'p')
		return (ft_print_ptr(va_arg(args, void *), flags));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(args, int), flags));
	if (specifier == 'u')
		return (ft_print_uint(va_arg(args, unsigned int), flags));
	if (specifier == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0, flags));
	if (specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1, flags));
	if (specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_init_flags(&flags);
			format++;
			format += ft_parse_format(format, args, &flags);
			count += ft_handle_format(*format, args, &flags);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
