/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:15:53 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 06:56:02 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief Handles sign and whitespace for ft_atoi.
//
// @param i Pointer to the current index in the string.
// @param str The input string.
// @return The sign of the number (1 or -1).
static int	sign_and_spaces(int *i, const char *str)
{
	int	sign;

	sign = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

// @brief Converts a string to an integer.
//
// @param str The input string.
// @return The converted integer.
long	ft_atol(const char *str)
{
	int		sign;
	int		i;
	long	res;

	i = 0;
	res = 0;
	sign = sign_and_spaces(&i, str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

// @brief Checks if a string contains only numeric characters.
//
// @param str The string to check.
// @return TRUE if the string is numeric, FALSE otherwise.
static t_bool	is_numeric(const char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

// @brief Validates a single command-line argument.
//
// @param arg The argument string to validate.
// @param type The type of argument being validated.
// @return TRUE if the argument is valid, FALSE otherwise.
t_bool	valid_arg(const char *arg)
{
	long	num;
	int		i;

	i = 0;
	sign_and_spaces(&i, arg);
	if (!is_numeric(&arg[i]))
		return (ft_putstr_fd(FTR_NOTNUM, 2), FALSE);
	if (ft_strlen(&arg[i]) > 10)
		return (ft_putstr_fd(FTR_NOTINT, 2), FALSE);
	num = ft_atol(arg);
	if (num > 2147483647 || num <= 0)
		return (ft_putstr_fd(FTR_BADNUM, 2), FALSE);
	return (TRUE);
}
