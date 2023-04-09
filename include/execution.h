/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:38:12 by absaid            #+#    #+#             */
/*   Updated: 2023/04/09 08:40:46 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define RIGHT 0
# define LEFT 1

t_token		*wildmatch(char *pattern);
void		execution(t_ast *ast, t_env *myenv);
void		exec_pipe(t_ast *ast, t_env *myenv);
void		exec_cmd(t_ast *ast, t_env *myenv);
void		exec_redir(t_ast *ast, t_env *myenv);
void		exec_subshell(t_ast *ast, t_env *myenv);
void		exec_oper(t_ast *ast, t_env *myenv);
char		*expand_prime(char *str, t_env *env);
t_token		*expand(char *str, t_env *env, int flag);
void		expand_change(t_token **list, t_env *myenv);
void		wildcard_change(t_token **list);
void		close_pipe(int fds[2]);
int			count_words(char *str, char c);
void		exit_status(int status);
void		set_statu(int status);
void		set_statug(int status);
void		param_sig(int signum);
typedef struct s_vartrans_list
{
	int		i;
	char	*str;
	char	**arg;
	t_token	*tmp;
}			t_vartrans_list;
#endif