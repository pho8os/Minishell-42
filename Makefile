# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 20:58:04 by absaid            #+#    #+#              #
#    Updated: 2023/03/12 04:13:11 by yettabaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -L/$(shell brew --prefix readline)/lib -lreadline -fsanitize=address -g

SRCS = main.c lexing/lexer.c lexing/lexer_lst.c builtins/builtins.c

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
