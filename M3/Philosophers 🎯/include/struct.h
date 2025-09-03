/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:16:26 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 09:29:09 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

struct	s_sim;

typedef struct s_philo
{
	// Unique identifier for the philosopher (e.g., 1, 2, 3...).
	int				id;
	// Time of the last meal (specific to each philosopher).
	long long		last_meal_time;
	// Meal counter (specific to each philosopher).
	int				meals_eaten;
	// The thread for this philosopher.
	pthread_t		thread;
	// Pointer to the simulation data.
	struct s_sim	*sim;
}	t_philo;

typedef struct s_sim
{
	// Total number of philosophers.
	int				num_philo;
	// Time before starving (in ms).
	int				time_to_die;
	// Time to eat (in ms).
	int				time_to_eat;
	// Time to sleep (in ms).
	int				time_to_sleep;
	// Number of meals to eat (optional, -1 if disabled).
	int				num_must_eat;
	// Start time of the simulation.
	long long		start_time;
	// Flag to stop the simulation.
	t_bool			sim_end_flag;
	// Array of all philosopher structures.
	t_philo			*philos;
	// Array of mutexes for the forks.
	pthread_mutex_t	*forks;
	// Mutex to protect display and shared data.
	pthread_mutex_t	protection_mutex;
}	t_sim;

#endif
