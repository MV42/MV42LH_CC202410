/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal, siginfo_t *info, void *more_info)
{
	static char		c;
	static int		bit;
	static pid_t	pid;

	(void)more_info;
	if (info->si_pid)
		pid = info->si_pid;
	if (SIGUSR1 == signal)
		c |= (0b10000000 >> bit);
	else if (SIGUSR2 == signal)
		c &= ~(0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if ('\0' == c)
		{
			my_kill(pid, SIGUSR2);
			c = 0;
			return (ft_printf("\n"), (void)1);
		}
		write(STDOUT_FILENO, &c, 1);
		c = 0;
	}
	my_kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: Usage\n./server\n");
		return (EXIT_FAILURE);
	}
	ft_printf("Server PID: %d\n", getpid());
	my_signal(SIGUSR1, sig_handler, true);
	my_signal(SIGUSR2, sig_handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
