# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 20:58:04 by absaid            #+#    #+#              #
#    Updated: 2023/04/11 09:02:15 by yettabaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = minishell

READLINE_PATH=$(shell brew --prefix readline)

CFLAGS = -Wall -Wextra -Werror  -Iinclude -g

HEADER = ./include/builtins.h ./include/execution.h ./include/lexer.h ./include/minishell.h ./include/parser.h ./Libft-42/libft.h

LIBFT = Libft-42/libft.a

SRCS = main.c \
lexing/lexer_utils.c lexing/tokenizer.c lexing/lexer_lst.c\
parsing/ast_const.c parsing/parser.c parsing/utils_parser.c parsing/heredoc.c parsing/parser_priorities.c \
execution/execution.c execution/exec_pipe.c execution/exec_cmd.c execution/expand.c execution/exec_redir.c execution/expand_utils.c \
execution/exec_oper_subshell.c execution/wildcard.c execution/signal_exitstatus.c execution/utils_exec.c libgc/gc.c  libgc/gc_utils.c \
builtins/builtins.c builtins/pwd.c builtins/export.c builtins/echo.c builtins/cd.c builtins/utils.c builtins/unset.c builtins/env.c builtins/exit.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C Libft-42
	$(CC) $(CFLAGS) $(LIBFT) -L $(READLINE_PATH)/lib -lreadline -o $(NAME) $^

%.o: %.c $(HEADER) 
	$(CC) $(CFLAGS) -I $(READLINE_PATH)/include -c $< -o $@ 

clean:
	make clean -C Libft-42
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME) $(LIBFT)

re: fclean all 

.PHONY: clean fclean re all
