/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:38:12 by absaid            #+#    #+#             */
/*   Updated: 2023/04/06 07:15:30 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define RIGHT 0
# define LEFT 1

typedef struct s_wild
{
	char *match;
	struct s_wild *next;
} t_wild;

char *expand(char *str, t_env *env);
char *wildmatch(char *pattern);
void execution(t_ast *ast, t_env *myenv);
void exec_pipe(t_ast *ast, t_env *myenv);
void exec_cmd(t_ast *ast, t_env *myenv);
void exec_redir(t_ast *ast, t_env *myenv);
void exec_subshell(t_ast *ast, t_env *myenv);
void exec_oper(t_ast *ast, t_env *myenv);
void exit_status(t_env *myenv ,int status);
char *expand(char *str, t_env *env);
char *change(t_token *list, t_env *myenv);

typedef struct s_vartrans_list
{
    int i;
    char *str;
    char **arg;
    t_token *tmp;
} t_vartrans_list;
#endif