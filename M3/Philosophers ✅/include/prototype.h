/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:16:29 by mavander          #+#    #+#             */
/*   Updated: 2025/08/15 09:10:15 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "philo.h"

/*████████████████████████████████████████████████████████████████████████████*/
/*--utils--*/
// libft.c
size_t				ft_strlen(const char *str);
void				ft_putstr_fd(char *s, int fd);
long				ft_atol(const char *str);
// parse_args.c
t_bool				parse_arguments(int argc, char **argv, t_sim *sim);
// print_status.c
void				print_status(t_philo *philo, char *action);
// utils.c
void				*ft_calloc(unsigned int size);
long long			ft_get_time(void);
void				ft_sleep(long long time);
void				clean_all(t_sim *sim);
// validate_args.c
t_bool				valid_arg(const char *arg);

/*████████████████████████████████████████████████████████████████████████████*/
// main.c
int					main(int argc, char **argv);
// monitor.c
void				*check_philo_health(void *sim_ptr);
// philo_actions.c
void				get_fork(t_philo *philo);
void				start_eating(t_philo *philo);
void				release_forks(t_philo *philo);
// philo_states.c
void				start_sleeping(t_philo *philo);
void				start_thinking(t_philo *philo);
// philo_threads.c
void				wait_all_philo(t_sim *sim);
void				start_philo_threads(t_sim *sim);
// sim_init.c
t_sim				*init_sim(int argc, char **argv);

#endif
