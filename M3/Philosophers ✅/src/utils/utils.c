/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:15:48 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 11:14:22 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief Allocates memory and initializes it to zero.
//
// @param size The amount of memory to allocate in bytes.
// @return A pointer to the allocated memory, or NULL on failure.
void	*ft_calloc(unsigned int size)
{
	char			*ptr;
	unsigned int	i;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = '\0';
	return (ptr);
}

// @brief Gets the current time in milliseconds.
//
// @return The current time in milliseconds.
long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

// @brief Pauses execution for a specified time in milliseconds.
//
// @param time The duration to sleep in milliseconds.
void	ft_sleep(long long time)
{
	long long	start_time;

	start_time = ft_get_time();
	while (ft_get_time() - start_time < time)
		usleep(100);
}

// @brief Cleans up allocated resources and destroys mutexes.
//
// @param sim The simulation data structure to clean.
void	clean_all(t_sim *sim)
{
	int	i;

	if (!sim)
		return ;
	i = 0;
	if (sim->forks)
	{
		while (i < sim->num_philo)
			pthread_mutex_destroy(&sim->forks[i++]);
		free(sim->forks);
	}
	pthread_mutex_destroy(&sim->protection_mutex);
	if (sim->philos)
		free(sim->philos);
	free(sim);
}
