/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:04:19 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/07 10:01:45 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	dupenv(t_env **myenv, char **env);
char	**subbing(char *env);
// int	    builting(t_env *myenv, char **arg);
int	    builting(t_env *myenv, char **arg, char **argzb);

void	env(t_env *myenv);
void	pwd(t_env *myenv);
void	cd(t_env *myenv, char **arg);
void	unset(t_env *myenv, char **arg);
void	export(t_env *myenv, char **arg);
void	ft_exit(t_env *myenv, char **arg);
void	echo(t_env *myenv, char **arg);

//utils
int is_digit(char *str);
void	print_export(t_env *myenv);
void	builtins_error(const char *cmd, const char *arg, const char *msg);
void	free_tab(char **str);
void	print_arg(char **arg); //!!
#endif