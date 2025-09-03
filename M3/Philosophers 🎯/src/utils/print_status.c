/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:15:40 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 11:15:10 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// @brief Prints the status of a philosopher.
//
// @param philo The philosopher printing the status.
// @param status The status message to print.
void	print_status(t_philo *philo, char *status)
{
	long long	current_time;
	int			id;

	pthread_mutex_lock(&philo->sim->protection_mutex);
	if (philo->sim->sim_end_flag)
	{
		pthread_mutex_unlock(&philo->sim->protection_mutex);
		return ;
	}
	current_time = ft_get_time() - philo->sim->start_time;
	id = philo->id;
	printf("%lld\t%d\t%s\n", current_time, id, status);
	pthread_mutex_unlock(&philo->sim->protection_mutex);
}
