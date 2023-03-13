/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:04:19 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 22:01:55 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_varibles t_varibles;
typedef struct s_env t_env;

void test_builting(t_varibles *v); //!!
void print_env(t_env *envr);
void pwd(void);
void cd(const char *path, t_varibles *v);
void export(char **arg, t_varibles *v);
void dupenv(char **env, t_varibles *v);
void addboth(t_varibles *v, char *variable, char *value, int flag);
#endif