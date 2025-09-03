/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:16:04 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 10:07:46 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief Checks if all philosophers have eaten the required number of meals.
//
// @param sim The simulation data structure.
// @return TRUE if all philosophers have eaten enough, FALSE otherwise.
static t_bool	all_philos_have_eaten(t_sim *sim)
{
	int	i;

	i = 0;
	if (sim->num_must_eat == -1)
		return (FALSE);
	while (i < sim->num_philo)
	{
		if (sim->philos[i].meals_eaten < sim->num_must_eat)
			return (FALSE);
		i++;
	}
	sim->sim_end_flag = TRUE;
	return (TRUE);
}

// @brief Checks if a philosopher has died from starvation.
//
// @param sim The simulation data structure.
// @return TRUE if a philosopher has died, FALSE otherwise.
static t_bool	a_philo_has_died(t_sim *sim)
{
	int			i;
	long long	current_time;

	i = 0;
	while (i < sim->num_philo)
	{
		if ((ft_get_time() - sim->philos[i].last_meal_time) > sim->time_to_die)
		{
			sim->sim_end_flag = TRUE;
			current_time = ft_get_time() - sim->start_time;
			printf("%lld\t%d\t%s\n", current_time, sim->philos[i].id, "died 💀");
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

// @brief The main monitoring function that runs in a separate thread.
//
// It continuously checks for philosopher deaths and whether all
// philosophers have eaten the required number of meals.
//
// @param sim_ptr A pointer to the simulation data structure.
// @return Always returns NULL.
void	*check_philo_health(void *sim_ptr)
{
	t_sim	*sim;

	sim = sim_ptr;
	while (1)
	{
		pthread_mutex_lock(&sim->protection_mutex);
		if (a_philo_has_died(sim) || all_philos_have_eaten(sim))
		{
			pthread_mutex_unlock(&sim->protection_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&sim->protection_mutex);
		ft_sleep(1);
	}
	return (NULL);
}
