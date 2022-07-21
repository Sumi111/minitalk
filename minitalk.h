/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:15:31 by sfathima          #+#    #+#             */
/*   Updated: 2021/12/27 11:13:24 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int			ft_printf(char *arg, ...);
int			ft_char(char c, int ct);
int			ft_int(long n, int ct);
int			ft_atoi(const char *str);

#endif
