/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:16:09 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 06:00:41 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief The philosopher starts sleeping.
//
// @param philo The philosopher's data structure.
void	start_sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping 💤");
	ft_sleep(philo->sim->time_to_sleep);
}

// @brief The philosopher starts thinking.
//
// @param philo The philosopher's data structure.
void	start_thinking(t_philo *philo)
{
	print_status(philo, "is thinking 💭");
}
