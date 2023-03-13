/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:04:19 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 05:36:28 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "../Libft-42/libft.h"
#include "minishell.h"

void test_builting(t_token *tok, t_env **myenv, t_env **myexp); //!!
void print_env(t_env *envr);
void pwd(void);
void cd(const char *path, t_env **myenv, t_env **myexp);
void export(char **arg, t_env **myenv, t_env **myexp);
void dupenv(char **env, t_env **myenv, t_env **myexp);
#endif