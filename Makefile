# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 17:34:31 by sfathima          #+#    #+#              #
#    Updated: 2021/12/30 12:38:06 by sfathima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc		= gcc
CFLAG	= -Wall -Werror -Wextra
RM		= rm -f

all:
	$(cc) $(CFLAG) server.c utlis.c -o server
	$(cc) $(CFLAG) client.c utlis.c -o client

bonus:
	$(cc) $(CFLAG) server_bonus.c utlis.c -o server
	$(cc) $(CFLAG) client_bonus.c utlis.c -o client

clean	:
	$(RM) server client
fclean	: clean
	
re		: fclean all

.PHONY : all clean fclean re
