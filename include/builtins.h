/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:04:19 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 08:56:07 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_utils
{
	t_env	*exp;
	t_env	*tmp;
	t_env	*tmp2;
}			t_utils;
void		dupenv(t_env **myenv, char **env);
char		**subbing(char *env);
int			builting(t_env **myenv, char **arg);
void		env(t_env *myenv);
void		pwd(void);
void		cd(t_env *myenv, char **arg);
void		unset(t_env **myenv, char **arg);
void		export(t_env **myenv, char **arg);
void		ft_exit(char **arg);
void		echo(char **arg);
int			is_digit(char *str);
void		print_export(t_env *myenv);
#endif