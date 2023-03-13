# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 20:58:04 by absaid            #+#    #+#              #
#    Updated: 2023/03/13 21:43:35 by yettabaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

READLINE_PATH=$(shell brew --prefix readline)

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

HEDER = includes/builtins.h includes/executor.h includes/lexer.h includes/minishell.h includes/parser.h

SRCS = main.c lexing/lexer.c lexing/lexer_lst.c \
builtins/builtins.c builtins/pwd.c builtins/export.c \
builtins/unset.c builtins/env.c builtins/exit.c \
builtins/echo.c builtins/cd.c builtins/utils.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

Libft-42/libft.a:
	make bonus -C Libft-42

$(NAME): $(OBJS) Libft-42/libft.a
	$(CC) $(CFLAGS) -L $(READLINE_PATH)/lib -lreadline -o $(NAME) $^

%.o: %.c $(HEDER) 
	$(CC) $(CFLAGS) -I $(READLINE_PATH)/include -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C Libft-42

fclean: clean 
	rm -f $(NAME)
	make fclean -C Libft-42

re: fclean all 

.PHONY: clean fclean re all
