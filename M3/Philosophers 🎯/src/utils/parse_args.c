/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:15:37 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 07:02:06 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief Parses and validates command-line arguments.
//
// @param argc The number of command-line arguments.
// @param argv An array of command-line argument strings.
// @param sim The simulation data structure to populate.
// @return TRUE on success, FALSE on failure.
t_bool	parse_arguments(int argc, char **argv, t_sim *sim)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (FALSE);
	}
	sim->num_philo = ft_atol(argv[1]);
	sim->time_to_die = ft_atol(argv[2]);
	sim->time_to_eat = ft_atol(argv[3]);
	sim->time_to_sleep = ft_atol(argv[4]);
	if (!valid_arg(argv[1]) || !valid_arg(argv[2])
		|| !valid_arg(argv[3]) || !valid_arg(argv[4]))
		return (FALSE);
	if (argc == 6)
	{
		sim->num_must_eat = ft_atol(argv[5]);
		if (!valid_arg(argv[5]))
			return (FALSE);
	}
	else
		sim->num_must_eat = -1;
	return (TRUE);
}
