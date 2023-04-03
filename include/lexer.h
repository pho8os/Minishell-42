/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:32:37 by absaid            #+#    #+#             */
/*   Updated: 2023/04/03 02:56:10 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H
// # include "minishell.h"
// typedef enum s_flag
// {
// 	PIPE = 0,
// 	SAND = 1, 
// 	RIN = 2, 
// 	ROUT = 3, 
// 	OPAR = 4, 
// 	CPAR = 5, 
// 	DQ = 6,
// 	SQ = 7,
// 	TAB = 8,
// 	SPACE = 9,
// 	OR = 10,
// 	AND = 11,
// 	HEREDOC = 12,
// 	APPEND = 13,
// 	WORD = 14,
// 	END = 15,
// 	EXPD = 16,
// 	WILD = 17,
// 	BOTH = 18,
// 	PAR = 19,
// 	NUL = -1,
// }	e_flag;

// typedef struct s_token
// {
// 	e_flag			type;
// 	e_flag			change;
// 	char			*token;
// 	struct s_token	*down;
// 	struct s_token	*next;
// 	struct s_token	*prev;
// } t_token;
# include <stdbool.h>
typedef enum s_flag
{
	WORD = 0,
	DQ = 1,
	SQ = 2,
	PIPE = 3,
	RIN = 4, 
	ROUT = 5, 
	OPAR = 6, 
	CPAR = 7, 
	SPACE = 8,
	AND = 9,
	OR = 10,
	HEREDOC = 11,
	APPEND = 12,
	PAR,
	REDIR,
	END,
}	e_flag;

typedef struct s_token
{
	e_flag			type;
	bool			hdoc;
	bool			expand;
	char			*token;
	struct s_token	*next;
	struct s_token	*down;
	struct s_token	*prev;
} t_token;
// int chek(t_token *tok);
// char *dup_c(char c);
// int chek_back(char *str, char c, int star, int end);
// t_token *lexer(char *cmdl);
// t_token *test(char *cmdl, int ind, int *i);
// t_token	*newtok(char *token, e_flag type, e_flag change);
// int	lstsize_token(t_token *lst);
// t_token	*lasttok(t_token *lst);
// void	addtok(t_token **lst, t_token *new);
// void	cleartok(t_token **lst);
// void	add_down(t_token **lst, t_token *new, int f);
// // t_token	*lasttok_down(t_token *lst, int *i);
// t_token	*lasttok_down(t_token *lst);
// int	size_down(t_token *lst);
//pphobos

t_token *ft_newtoken(e_flag type, char *word, int flag, int hdoc);
t_token	*lasttok(t_token *lst);
void	addtok(t_token **lst, t_token *new);
t_token *tokenizer(char *c);

#endif