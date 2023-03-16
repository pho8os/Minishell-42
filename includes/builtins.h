/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:04:19 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/16 01:41:59 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_varibles t_varibles;
typedef struct s_env t_env;

void test_builting(t_varibles *v); //!!

void    env(t_varibles *v);
void pwd(void);
void dupenv(char **env, t_varibles *v);
void cd(t_varibles *v, char **arg);
void unset(t_varibles *v, char **arg);
void export(t_varibles *v, char **arg);
void exit_status(t_varibles *v, char **arg);
void echo(t_varibles *v, char **arg);
void delone_env(t_env **env);
char **subbing(char *env);

//utils
void print_arg(char **arg); //!!
void print_env(t_env *env, int flag);
void addvalue(t_varibles *v, const char *variable, char *value);

#endif