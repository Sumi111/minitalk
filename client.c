/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:43:52 by sfathima          #+#    #+#             */
/*   Updated: 2021/12/30 12:36:14 by sfathima         ###   ########.fr       */
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
			bit--;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid_server;

	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		if (pid_server <= 0)
		{
			ft_printf("Wrong format. Try \"./client Server_PID Message\"");
			return (0);
		}
		send_msg(pid_server, argv[2]);
	}
	else
		ft_printf("Wrong Format. Try \"./client Server_PID Message\"");
	return (0);
}
