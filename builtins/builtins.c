/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:03:39 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/16 04:12:11 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

char **subbing(char *env)
{
	int i;
	char **varandval;
	
	i = 0;
	while(env[++i])
		if(env[i] == '=')
			break;
	varandval = malloc(sizeof(char *) * 2);
	if (!varandval)
		return(NULL);
	varandval[0] = ft_substr(env, 0, i);
	varandval[1] = ft_substr(env, i + 1, ft_strlen(env + i));
	if(!ft_strncmp("SHLVL", varandval[0], 6))
	{
		i = ft_atoi(varandval[1]);
		(i >= 0) && (i++);
		(i < 0) && (i = 0);
		free(varandval[1]);
		varandval[1] = ft_itoa(i);
	}
	return(varandval);
}


void dupenv(char **env, t_varibles *v)
{
	int i;
	char **subenv;
	
	i = -1;
	v->myenv  = NULL;
	while (env[++i])
	{
		subenv = subbing(env[i]);
		addbenv(&v->myenv, newenv(subenv[0], subenv[1], 1));
		free(subenv);
	}
}

void test_builting(t_varibles *v) //!!
{
    char **arg;
    int size_tok = lstsize_token(v->tok);
    int i = 0;
	// printf("==%d\n", size_tok);
    arg = malloc(sizeof(char *) * (size_tok + 1));
    arg[size_tok] = NULL;
	t_token *tmp = v->tok;
    while (tmp)
    {
		if (tmp->type == WORD)
        	arg[i++] = tmp->token;
        tmp = tmp->next;
    }
	cleartok(&v->tok);
    if (ft_strncmp("pwd", arg[0], 3) == 0)
        pwd();
    else if (ft_strncmp("cd", arg[0], 2) == 0)
        cd(v, arg + 1);
    else if (ft_strncmp("env", arg[0], 3) == 0)
        env(v);
    else if (ft_strncmp("export", arg[0], 7) == 0)
        export(v , arg + 1);
    else if (ft_strncmp("unset", arg[0], 5) == 0)
        unset(v , arg + 1);
    else if (ft_strncmp("exit", arg[0], 4) == 0)
        exit_status(v , arg);
    else if (ft_strncmp("echo", arg[0], 4) == 0)
        echo(v , (arg + 1));
	i = -1;
	while(arg[++i])
		free(arg[i]);
	free(arg);	
}







