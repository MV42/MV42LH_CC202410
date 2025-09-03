/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:16:14 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 09:43:15 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief Initializes the entire simulation.
//
// @param argc The number of command-line arguments.
// @param argv An array of command-line argument strings.
// @return A pointer to the initialized simulation structure,
// @return or NULL on failure.
t_sim	*init_sim(int argc, char **argv)
{
	t_sim	*sim;
	int		i;

	sim = ft_calloc(sizeof(t_sim));
	if (!sim)
		return (NULL);
	if (!parse_arguments(argc, argv, sim))
		return (free(sim), NULL);
	sim->philos = ft_calloc(sim->num_philo * sizeof(t_philo));
	sim->forks = ft_calloc(sim->num_philo * sizeof(pthread_mutex_t));
	if (!sim->philos || !sim->forks)
		return (clean_all(sim), NULL);
	i = -1;
	while (++i < sim->num_philo)
		pthread_mutex_init(&sim->forks[i], NULL);
	pthread_mutex_init(&sim->protection_mutex, NULL);
	i = -1;
	while (++i < sim->num_philo)
	{
		sim->philos[i].id = i + 1;
		sim->philos[i].sim = sim;
	}
	return (sim);
}
