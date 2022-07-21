/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:30:42 by sfathima          #+#    #+#             */
/*   Updated: 2021/12/27 11:13:04 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;
	pid_t		pid_c;

	pid_c = info->si_pid;
	context = NULL;
	if (sig == SIGUSR1)
		c = c + c | 1;
	else
		c = c << 1;
	bit++;
	if (bit == 8)
	{
		if (c != '\0')
			write(1, &c, 1);
		else
			kill(pid_c, SIGUSR2);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid_server;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigemptyset(&sa.sa_mask);
	pid_server = getpid();
	ft_printf("PID: %d \n", pid_server);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
