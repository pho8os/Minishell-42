# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 20:58:04 by absaid            #+#    #+#              #
#    Updated: 2023/04/03 02:55:25 by yettabaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

READLINE_PATH=$(shell brew --prefix readline)

CFLAGS = -Wall -Wextra -Werror  -Iinclude -g -fsanitize=address -fsanitize=undefined

HEDER = include/builtins.h include/executor.h include/lexer.h include/minishell.h include/parser.h include/filtrage.h

SRCS = main.c \
lexing_phobos/lexer_utils.c lexing_phobos/tokenizer.c \
parsing/ast_const.c parsing/parser.c \
# builtins/builtins.c builtins/pwd.c builtins/export.c builtins/echo.c builtins/cd.c builtins/utils.c builtins/unset.c builtins/env.c builtins/exit.c \
# filtrage/expanding.c \
execution/execution.c execution/exec_pipe.c execution/exec_cmd.c \
#lexing/lexer.c lexing/lexer_lst.c lexing/lexer_utils.c\

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
