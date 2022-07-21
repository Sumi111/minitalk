/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:43:52 by sfathima          #+#    #+#             */
/*   Updated: 2021/12/30 13:10:55 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(pid_t pid, char *str)
{
	int		i;
	int		bit;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		bit = 7;
		c = str[i];
		while (bit >= 0)
		{
			if ((c >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit--;
		}
		i++;
	}
	while (bit-- <= 6)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Server received your message");
	exit (0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid_server;

	if (argc == 3)
	{
		signal(SIGUSR2, handler);
		pid_server = ft_atoi(argv[1]);
		if (pid_server <= 0)
		{
			ft_printf("Wrong format. Try \"./client Server_PID Message\"");
			return (0);
		}
		send_msg(pid_server, argv[2]);
		while (1)
			pause();
	}
	else
		ft_printf("Incorrect format. Try \"./client Server_PID Message\"");
	return (0);
}
