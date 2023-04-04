/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:28:56 by absaid            #+#    #+#             */
/*   Updated: 2023/04/04 05:24:03 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"


char *getval(char *str, int *i, t_env *env)
{
	char *s;
	int j = *i + 1;
	// int x = 0;
	
	if(str[j] == '?')
	{
		if(!ft_memcmp(env->variable, "?", ft_strlen(env->variable) + 1)) 
			return(*i += 2, s = env->value, s);
	}
	else if(str[j] == '_' || ft_isalpha(str[j]))
	{
		j++;
		while((ft_isalnum(str[j]) || str[j] == '_') && str[j])
			j++;
	}
	else
		return(*i += 1, ft_strdup("$"));
		
	s = ft_substr(str, *i + 1, j - (*i + 1));
		// printf("ptr->%s\n", s);
	*i += j - (*i);
	while(env)
	{
		if(!ft_memcmp(env->variable, s, ft_strlen(env->variable) + 1) && env->print != -2) // hide all envirment exept ?
			return(s = env->value, s);
		env = env->next;
	}
	return(ft_strdup(""));
}

char *expand(char *str, t_env *env)
{
	int i;
	int j;
	char *s = "";
	char *p;

	if(!ft_strchr(str, '$'))
		return (str);
	i = -1;
	j = 0;
	while(str[++i])
	{
		if (str[i] == '$' && str[i])
		{
			p = ft_substr(str , j, i - j);
			s = ft_strjoin(s, p);
			s = ft_strjoin(s , getval(str, &i, env));
			j = i;
			// printf("c->%c i->%d\n", str[i], i);
		}
		if(i > (int)ft_strlen(str) - 1)
			break;
	}
	p = ft_substr(str , j, i - j);
	s = ft_strjoin(s, p);
	return (s);
}

char *change(t_token *list, t_env *myenv)
{
	if (list->expand)
		return (expand(list->token, myenv));
	return (list->token);	
}