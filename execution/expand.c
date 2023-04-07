/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:28:56 by absaid            #+#    #+#             */
/*   Updated: 2023/04/07 10:36:14 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void exit_status(t_env *myenv ,int status)
{
    myenv->value = ft_itoa(status);
}

char *change(t_token *list, t_env *myenv)
{
	// if(list->hdoc && ft_strchr(list->token, '$'))
	// 	return 	(wildmatch(list->token));
	if (list->expand)
		return (expand(list->token, myenv));
	return (list->token);	
}


char *getv(char *str, t_env *env)
{
	while(env)
	{
		if(!ft_memcmp(env->variable, str, ft_strlen(env->variable) + 1) && env->print != -2)
			return(str = env->value, str);
		env = env->next;
	}
	return(NULL);
}

char *expand(char *str, t_env *env)
{

	int i = 0;
	int j;
	char *p;
	char *s = NULL;
	
	while(str[i])
	{
		if(str[i] != '$')
		{
			j = i;
			while(str[i] && str[i]!= '$')
				i++;
			p = ft_substr(str, j, i - j);
		}
		else if(str[i] == '$')
		{
			j = i + 1;
			
			if(str[j] && (str[j] == '_' || ft_isalpha(str[j])))
			{
				j++;
				while(str[j] && (str[j] == '_' || ft_isalnum(str[j])))
					j++;
				p = getv(ft_substr(str, i + 1, j - i - 1), env);
				i = j;
			}
			else if(str[j] == '?')
			{
				p = env->value;
				i += 2;
			}
			else
			{
				j = i + 1;
				while(str[j] && str[j]!= '$')
					j++;
				p = ft_substr(str, i, j - i);
				i = j;
			}
		}
		s = _strjoin(s, p);
	}
	return(s);
}

// t_token *expand(char *str, t_token *env)
// {
// 	t_token *expand;
// 	char **str;
// 	int i;

// 	i = 0;
// 	str = ft_split(expand_prime(str, env), ' ');
// 	while (str[i])
// 	{
		
// 	}
	
// }