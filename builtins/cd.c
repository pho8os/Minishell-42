/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:07 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 12:43:26 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cd_env(t_env *myenv, const char *variable, char *pwd, int flag)
{
	t_env	*find;

	find = ft_lstchr(myenv, variable);
	if (!find)
	{
		if (flag)
			addbenv(&myenv, newenv(dup_alloc(variable), pwd, 1));
		return (NULL);
	}
	if (flag)
	{
		free(find->value);
		find->value = pwd;
	}
	return (find->value);
}

void	execd(t_env *myenv, const char *path, const char *var)
{
	int		ret;
	char	*pwd;

	if (!path)
		return (set_statu(1), fd_printf(2, "cd %s not set\n", var));
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (set_statu(1), chdir(path), fd_printf(2,
				"cd: error retrieving current directory: getcwd: \
cannot access \
parent directories: No such file or directory\n"));
	ret = chdir(path);
	if (ret != 0)
		return (set_statu(1), perror(path));
	cd_env(myenv, "OLDPWD", pwd, 1);
	cd_env(myenv, "PWD", getcwd(NULL, 0), 1);
}

void	cd(t_env *myenv, char **arg)
{
	char	*oldpwd;

	set_statu(0);
	if (!ft_memcmp("~", arg[1], 2) || !arg[1])
		return (execd(myenv, cd_env(myenv, "HOME", NULL, 0), "HOME"));
	if (!ft_memcmp("-", arg[1], 2))
	{
		oldpwd = ft_strdup(cd_env(myenv, "OLDPWD", NULL, 0));
		execd(myenv, oldpwd, "OLDPWD");
		if (oldpwd)
			return (printf("%s\n", oldpwd), free(NULL));
		return ;
	}
	return (execd(myenv, arg[1], ""));
}
