# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 20:58:04 by absaid            #+#    #+#              #
#    Updated: 2023/03/05 02:11:53 by yettabaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -L/$(shell brew --prefix readline)/lib -lreadline #-fsanitize=address

SRCS = main.c lexing/lexer.c

all: $(NAME)


Libft-42/libft.a:
	make bonus -C Libft-42

$(NAME):$(SRCS) includes/minishell.h Libft-42/libft.a
	$(CC) $(CFLAGS) $(SRCS) Libft-42/libft.a -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C Libft-42

fclean: clean 
	rm -f $(NAME)
	make fclean -C Libft-42

re: fclean all 

.PHONY: clean fclean re all
