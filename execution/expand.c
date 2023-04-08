/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:28:56 by absaid            #+#    #+#             */
/*   Updated: 2023/04/08 08:24:51 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"



void change(t_token **list, t_env *myenv)
{
	t_token *tmp;
	t_token *tmp2;
	(void)myenv;
	
	tmp = *list;
	if (*list && (*list)->hdoc && ft_strchr((*list)->token, '*'))
	{
		*list = wildmatch((*list)->token);
		lasttok(*list)->next = tmp->next;
		return ;
	}
	while (*list)
	{
		tmp2 = *list;
		if ((*list)->next && (*list)->next->hdoc && ft_strchr((*list)->next->token, '*'))
		{
			(*list)->next = wildmatch((*list)->next->token);
			while (*list)
			{
				*list = (*list)->next;
				
			}
			
			// (*list)->next = tmp;
			// tmp2 = tmp2->next;
			printf("apah %s\n", (*list)->token);
			// printf("tzz %s\n", lasttok(tmp)->token);
			// lasttok(tmp)->next = *list;
		}
		else
			*list = (*list)->next;
	}
	
}
// char *change(t_token *list, t_env *myenv)
// {
// 	if(list->hdoc && ft_strchr(list->token, '$'))
// 		(wildmatch(list->token));
// 	if (list->expand)
// 		return (expand(list->token, myenv));
// 	return (list->token);
// }


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
	
	if  (!str)
		return(NULL);
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