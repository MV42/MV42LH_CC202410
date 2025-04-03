/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_kill(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
	{
		ft_printf("Kill failed");
		exit(EXIT_FAILURE);
	}
}

void	my_signal(int signal, void *handler, bool use_siginfo)
{
	struct sigaction	sa;

	sa.sa_handler = NULL;
	sa.sa_mask = (__sigset_t){0};
	sa.sa_flags = 0;
	sa.sa_restorer = NULL;
	if (use_siginfo)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signal, &sa, NULL) < 0)
	{
		ft_printf("sigaction failed");
		exit(EXIT_FAILURE);
	}
}
