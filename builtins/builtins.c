/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:03:39 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/13 05:32:43 by yettabaa         ###   ########.fr       */
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

void ft_swap(char **a, char **b)
{
    char *c;
    
    c = *a;
    *a = *b;
    *b = c;
}

void dupenv(char **env, t_env **myenv, t_env **myexp)
{
	int i;
	int j;
	char **subenv;
	
	i = -1;
	*myenv  = NULL;
	*myexp  = NULL;
	while (env[++i])
	{
		subenv = subbing(env[i]);
		ft_lstadd_back(myenv, ft_lstnew(subenv[0], subenv[1]));
	}
	i = -1;
	while(env[++i])
	{
		j = i - 1;
		while (env[++j])
			if (ft_strcmp(env[i], env[j]) >= 0)
                ft_swap(&env[i], &env[j]);
		subenv = subbing(env[i]);
		ft_lstadd_back(myexp, ft_lstnew(subenv[0], subenv[1]));
	}
}

void test_builting(t_token *tok, t_env **myenv, t_env **myexp) //!!
{
    char **arg;
    int size_tok = lstsize_token(tok);
    int i = 0;

    arg = malloc(sizeof(char *) * (size_tok + 1));
    arg[size_tok] = 0;
    while (tok)
    {
        arg[i++] = tok->token;
        tok = tok->next;
    }
    if (ft_strncmp("pwd", arg[0], 3) == 0)
        pwd();
    else if (ft_strncmp("cd", arg[0], 2) == 0)
        cd(arg[2], myenv, myexp);
    else if (ft_strncmp("env", arg[0], 3) == 0)
        print_env(*myenv);
    else if (ft_strncmp("export", arg[0], 7) == 0)
        export(arg, myenv, myexp);
}







