/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:35:04 by absaid            #+#    #+#             */
/*   Updated: 2023/04/07 09:01:52 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_ast
{
	int		type;
}			t_ast;

typedef struct s_command
{
	int		type;
	t_token	*list;
}			t_command;

typedef struct s_redir
{
	int		type;
	int		typeredir;
	int		fd_in;
	int		flags;
	char	*arg;
	t_token	*tok;
	t_ast	*trdr;
}			t_redir;

typedef struct s_subsh
{
	int		type;
	t_ast	*sub;
}			t_subsh;

typedef struct s_operator
{
	int		type;
	t_ast	*left;
	t_ast	*right;
}			t_operator;

t_ast		*new_cmd(t_token *list);
t_ast		*new_reder(void);
t_ast		*new_oper(int type, t_ast *left, t_ast *right);
t_ast		*new_sub(t_ast *tree);
t_ast *parser(t_token **tok, t_env *myenv);
t_ast		*parse_oper(t_token **tok);
t_ast		*parse_pipe(t_token **tok);
t_ast		*parse_cmd(t_token **tok);
t_ast		*parse_sub(t_token **tok);
t_ast		*redire_info(t_token **tok);
int		addback_redir(t_ast *tree, t_ast *addin);
void		addb_list(t_ast *ast, t_token **tok);
int			heredoc(char *delim);
char		*join_tokens(t_token *node);
#endif