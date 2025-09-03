/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:16:06 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 11:08:20 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief A philosopher acquires forks to be able to eat.
//
// @param philo The philosopher's data structure.
void	get_fork(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->sim->num_philo;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->sim->forks[right_fork]);
		print_status(philo, "has taken a fork 🍴");
		pthread_mutex_lock(&philo->sim->forks[left_fork]);
		print_status(philo, "has taken a fork 🍴");
	}
	else
	{
		pthread_mutex_lock(&philo->sim->forks[left_fork]);
		print_status(philo, "has taken a fork 🍴");
		pthread_mutex_lock(&philo->sim->forks[right_fork]);
		print_status(philo, "has taken a fork 🍴");
	}
}

// @brief The philosopher starts eating.
//
// @param philo The philosopher's data structure.
void	start_eating(t_philo *philo)
{
	print_status(philo, "is eating 🍝");
	pthread_mutex_lock(&philo->sim->protection_mutex);
	philo->last_meal_time = ft_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->sim->protection_mutex);
	ft_sleep(philo->sim->time_to_eat);
}

// @brief The philosopher releases the forks after eating.
//
// @param philo The philosopher's data structure.
void	release_forks(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->sim->num_philo;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->sim->forks[left_fork]);
		pthread_mutex_unlock(&philo->sim->forks[right_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->sim->forks[right_fork]);
		pthread_mutex_unlock(&philo->sim->forks[left_fork]);
	}
}
