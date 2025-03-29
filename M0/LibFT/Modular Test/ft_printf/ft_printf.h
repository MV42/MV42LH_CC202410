/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

// ft_printf_cspct.c
int		ft_printchar(int c);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printpct(void);

// ft_putnbr_base.c
int		ft_strlen(char *str);
int		ft_pn_b(long long n, char *base);
int		ft_print_ptr(unsigned long long ptr);

//ft_printf.c
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *format, ...);

#endif