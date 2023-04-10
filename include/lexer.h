/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:32:37 by absaid            #+#    #+#             */
/*   Updated: 2023/04/10 08:46:41 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

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
	SUBSHELL,
	REDIR,
	SIGHER,
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

typedef struct s_norm
{
    int    i;
    t_token *token;
    t_token *down;
    bool dq;
    bool sq;
    bool space;
    int x;
    int op;
    int cp;
} t_norm;

t_token *ft_newtoken(e_flag type, char *word, int flag, int hdoc);
t_token	*lasttok(t_token *lst);
void	addtok(t_token **lst, t_token *new);
t_token *tokenizer(char *c);
void	add_down(t_token **lst, t_token *new, int f);
t_token	*lasttok_down(t_token *lst);
int	size_token(t_token *lst);
// void norminit(t_norm *ptr);
// void norm_1(t_norm *n, char *c);
// void norm_2(t_norm *n, char *c);
// void norm_3(t_norm *n, char *c);
char *getword(char *str, int *index);
char *getq(char *str, int *index, char c);
int getflag(char c, int flag);
int allspace(int i, char *c);

#endif