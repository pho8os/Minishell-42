/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:38:12 by absaid            #+#    #+#             */
/*   Updated: 2023/04/08 07:17:43 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define RIGHT 0
# define LEFT 1
// # include "lexer.h"

char		*expand(char *str, t_env *env);
t_token		*wildmatch(char *pattern);
void		execution(t_ast *ast, t_env *myenv);
void		exec_pipe(t_ast *ast, t_env *myenv);
void		exec_cmd(t_ast *ast, t_env *myenv);
void		exec_redir(t_ast *ast, t_env *myenv);
void		exec_subshell(t_ast *ast, t_env *myenv);
void		exec_oper(t_ast *ast, t_env *myenv);
void		exit_status(t_env *myenv, int status);
int			_stat(t_env *myenv);
char		*expand(char *str, t_env *env);
// char		*change(t_token *list, t_env *myenv);
void change(t_token **list, t_env *myenv);
void		close_pipe(int fds[2]);
typedef struct s_vartrans_list
{
	int		i;
	char	*str;
	char	**arg;
	t_token	*tmp;
}			t_vartrans_list;
#endif