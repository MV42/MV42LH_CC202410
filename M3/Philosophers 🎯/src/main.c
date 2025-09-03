/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:15:58 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 06:16:39 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief Main entry point for the philosopher simulation.
//
// @param argc The number of command-line arguments.
// @param argv An array of command-line argument strings.
// @return 0 on successful execution, 1 on failure.
int	main(int argc, char **argv)
{
	t_sim		*sim;
	pthread_t	monitor_thread;

	sim = init_sim(argc, argv);
	if (!sim)
	{
		ft_putstr_fd("Simulation initialization failed.\n", 2);
		return (1);
	}
	start_philo_threads(sim);
	pthread_create(&monitor_thread, NULL, check_philo_health, sim);
	pthread_join(monitor_thread, NULL);
	wait_all_philo(sim);
	clean_all(sim);
	return (0);
}
