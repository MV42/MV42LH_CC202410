/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "minitalk.h"

enum
{
	READY,
	BUSY,
};

// client.c
void	end_handler(int signal);
void	active_handler(int signal);
void	send_char(char c, pid_t srv);
int		main(int argc, char **argv);

// server.c
void	sig_handler(int signal, siginfo_t *info, void *more_info);
int		main(int argc, char **argv);


// utils.c
void	my_kill(pid_t pid, int signal);
void	my_signal(int signal, void *handler, bool use_siginfo);

#endif