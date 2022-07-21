/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:33:42 by sfathima          #+#    #+#             */
/*   Updated: 2021/12/27 14:59:15 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_char(char c, int ct)
{
	write (1, &c, 1);
	ct++;
	return (ct);
}

int	ft_int(long n, int ct)
{
	if (n < 0)
	{
		write(1, "-", 1);
		ct++;
		n = -n;
	}
	if (n >= 10)
		ct = ft_int(n / 10, ct);
	ct = ft_char(n % 10 + '0', ct);
	return (ct);
}

int	ft_printf(char *str, ...)
{
	int		i;
	va_list	ap;
	int		ct;

	ct = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == 'd')
				ct = ft_int(va_arg(ap, int), ct);
		}
		else
			ct = ft_char(str[i], ct);
		i++;
	}
	va_end (ap);
	return (ct);
}

static int	ft_check(unsigned long n, int sign)
{
	if (n >= 2147483648UL && sign == 1)
		return (-1);
	else if (n > 2147483648UL && sign == -1)
		return (0);
	else
		return (n);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	n;

	sign = 1;
	n = 0;
	while (((*str >= 9) && (*str <= 13)) || (*str == ' '))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if ((*str >= '0') && (*str <= '9'))
			n = (n * 10) + (*str - '0');
		else
			break ;
		str++;
	}
	n = ft_check(n, sign);
	return (n * sign);
}
