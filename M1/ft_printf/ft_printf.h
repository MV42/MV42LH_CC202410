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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	width;
	int	precision;
	int	zero;
	int	minus;
	int	plus;
	int	space;
	int	hash;
}	t_flags;

/* Main function */
int		ft_printf(const char *format, ...);

/* Parsing functions */
int		ft_parse_format(const char *format, va_list args, t_flags *flags);
void	ft_init_flags(t_flags *flags);

/* Conversion functions */
int		ft_print_char(int c, t_flags *flags);
int		ft_print_str(char *str, t_flags *flags);
int		ft_print_ptr(void *ptr, t_flags *flags);
int		ft_print_int(int n, t_flags *flags);
int		ft_print_uint(unsigned int n, t_flags *flags);
int		ft_print_hex(unsigned int n, int uppercase, t_flags *flags);

/* Utils functions */
int		ft_handle_width(int width, int size, int zero);
void	ft_handle_precision(t_flags *flags, int *size);
int		ft_handle_minus(char *str, int size, t_flags *flags);

#endif
