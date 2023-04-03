/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:08:07 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/01 08:04:46 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

char *cd_env(t_env *myenv, const char *variable, char *pwd, int flag)
{
    t_env *find;

    find = ft_lstchr(myenv, variable);
    if (!find)
    {
        if (flag)
            addbenv(&myenv, newenv(ft_strdup(variable), pwd, 1));
        return(NULL);
    }
    if (flag)
    {
        free(find->value);
        find->value = pwd; 
    }
    return (find->value);
}

void execd(t_env *myenv, const char *path, const char *var)
{
    int ret;
    char *pwd;

    if (!path)
        return (builtins_error("cd", var, "not set\n"));
    pwd = getcwd(NULL, 0);
    if (!pwd)
        perror("");   
    ret = chdir(path);
    if (ret != 0)
        return (perror(path));
    cd_env(myenv, "OLDPWD", pwd, 1);
    cd_env(myenv, "PWD", getcwd(NULL, 0), 1);
}

void cd(t_env *myenv, char **arg)
{
    char *oldpwd;
    
    // print_arg(arg);
    if (!ft_memcmp("~", arg[1], 2) || !arg[1])
        return (execd(myenv, cd_env(myenv, "HOME", NULL, 0), "HOME"));
    if (!ft_memcmp("-", arg[1], 2))
    {
        oldpwd = ft_strdup(cd_env(myenv, "OLDPWD", NULL, 0));
        execd(myenv, oldpwd, "OLDPWD");
        if (oldpwd)
            return (printf("%s\n", oldpwd), free(oldpwd));
        return ;    
    }
    return(execd(myenv, arg[1], ""));
}