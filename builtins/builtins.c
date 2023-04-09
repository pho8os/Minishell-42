/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:03:39 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/09 08:34:44 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"


char **subbing(char *env)
{
	int i;
	char **varandval;
	
	i = -1;
	while(env[++i])
		if(env[i] == '=')
			break;
	varandval = malloc(sizeof(char *) * 3);
	if (!varandval)
		return(NULL);
	varandval[0] = ft_substr(env, 0, i);
	varandval[1] = ft_substr(env, i + 1, ft_strlen(env + i));
	varandval[2] = NULL;
	if(!ft_memcmp("SHLVL", varandval[0], 6))
	{
		i = ft_atoi(varandval[1]);
		(i >= 0) && (i++);
		(i < 0) && (i = 0);
		free(varandval[1]);
		varandval[1] = ft_itoa(i);
	}
	return(varandval);
}

void dupenv(t_env **myenv, char **env)
{
	int i;
	char **subenv;
	
	i = -1;
	if (!env[0])
		return(addbenv(myenv, newenv(ft_strdup("PWD"), getcwd(NULL, 0), 1)),
		addbenv(myenv, newenv(ft_strdup("SHLVL"), ft_strdup("1"), 1)));
	while (env[++i])
	{
		subenv = subbing(env[i]);
		addbenv(myenv, newenv(subenv[0], subenv[1], 1));
		free(subenv);
	}
}

int builting(t_env *myenv, char **arg)
{
    if (!ft_memcmp("pwd", arg[0], 4))
        return (pwd(), 1);
    else if (!ft_memcmp("cd", arg[0], 3))
        return (cd(myenv, arg), 1);
    else if (!ft_memcmp("env", arg[0], 4 ) && !arg[1])
        return (env(myenv), 1);
    else if (!ft_memcmp("export", arg[0], 7))
        return (export(myenv , arg), 1);
    else if (!ft_memcmp("unset", arg[0], 6))
        return (unset(myenv , arg), 1);
    else if (!ft_memcmp("exit", arg[0], 5))
        return (ft_exit(arg), 1);
    else if (!ft_memcmp("echo", arg[0], 5))
        return (echo(arg), 1);
	else
		return (0);	
}







