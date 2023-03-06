/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:32:37 by absaid            #+#    #+#             */
/*   Updated: 2023/03/06 18:51:36 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

# include "minishell.h"

typedef enum s_flag
{
	WORD = 0,
	DQ = 1,
	SQ = 2,
	PIPE = 3,
	RIN = 4, 
	ROUT = 5, 
	SAND = 6, 
	POPEN = 7, 
	PCLOSE = 8, 
	SPACE = 9,
	OR = 10,
	AND = 11,
	HEREDOC = 12,
	APPEND = 13,
	WILDCARD = 14,
}	e_flag;

typedef struct s_token
{
	e_flag				type;
	char			*token;
	struct s_token	*next;
	struct s_token	*prev;
} t_token;
// t_token	*newtok(e_flag type, char *token):
t_token *lexer(char *cmdl);
t_token *test(char *cmdl, int ind, int *i);
#endif