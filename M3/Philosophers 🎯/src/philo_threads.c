/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:16:12 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 11:02:51 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief The main lifecycle of a philosopher.
//
// This function contains the loop that defines the philosopher's
// behavior: eating, sleeping, and thinking.
//
// @param philo_ptr A pointer to the philosopher's data structure.
// @return Always returns NULL.
static void	*philo_lifecycle(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	if (philo->sim->num_philo == 1)
	{
		print_status(philo, "has taken a fork 🍴");
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_sleep(1);
	while (1)
	{
		get_fork(philo);
		start_eating(philo);
		release_forks(philo);
		start_sleeping(philo);
		start_thinking(philo);
		pthread_mutex_lock(&philo->sim->protection_mutex);
		if (philo->sim->sim_end_flag)
			return (pthread_mutex_unlock(&philo->sim->protection_mutex), NULL);
		pthread_mutex_unlock(&philo->sim->protection_mutex);
	}
	return (NULL);
}

// @brief Waits for all philosopher threads to complete.
//
// @param sim The simulation data structure.
void	wait_all_philo(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_philo)
		pthread_join(sim->philos[i++].thread, NULL);
}

// @param sim The simulation data structure.
void	start_philo_threads(t_sim *sim)
{
	int	i;

	i = 0;
	sim->start_time = ft_get_time();
	while (i < sim->num_philo)
	{
		sim->philos[i].last_meal_time = sim->start_time;
		pthread_create(&sim->philos[i].thread, NULL,
			philo_lifecycle, &sim->philos[i]);
		i++;
	}
}
