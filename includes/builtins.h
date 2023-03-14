/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:04:19 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/14 23:22:57 by yettabaa         ###   ########.fr       */
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
void export(t_varibles *v, char **arg);
void addboth(t_varibles *v, char *variable, char *value, int flag);
void addvalue(t_varibles *v, const char *variable, char *value, int flag);
void print_env(t_env *penv, const char *str, int flag);
void delone_env(t_env **env);
#endif