/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:30:42 by sfathima          #+#    #+#             */
/*   Updated: 2021/12/27 14:59:09 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;

	info = NULL;
	context = NULL;
	if (sig == SIGUSR1)
		c = c + c | 1;
	else if (sig == SIGUSR2)
		c = c << 1;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
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
	pid_server = getpid();
	ft_printf("PID: %d \n", pid_server);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
