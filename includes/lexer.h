/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:32:37 by absaid            #+#    #+#             */
/*   Updated: 2023/03/04 21:00:53 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

# include "minishell.h"

typedef struct s_token
{
	int				type;
	char			*token;
	struct s_token	*prev;
	struct s_token	*next;
} t_token;

#define TOKEN_WORD  0
#define TOKEN_PIPE  1
#define TOKEN_OR  2
#define TOKEN_AND  3
#define TOKEN_REDIRECT_INPUT  4
#define TOKEN_REDIRECT_OUTPUT  5
#define TOKEN_HERE_DOC  6
#define TOKEN_REDIRECT_APPEND  7
#define SINGLEQ  8
#define DOUBLEQ  9
#define COMMERCE  10
#define SPACE  11
#define DOLLAR  12
#define OPEN_BRACE  13
#define CLOSE_BRACE  14


#define NOT_EXPECT  42

t_token	*newtok(int type, char *token);
t_token *lexer(char *cmdl);
t_token *test(char *cmdl, int ind, int *i);
#endif