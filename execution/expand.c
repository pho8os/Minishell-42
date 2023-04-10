/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:28:56 by absaid            #+#    #+#             */
/*   Updated: 2023/04/10 05:03:38 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

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

char *expand_prime(char *str, t_env *env)
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
				p = ft_itoa(g_stat);
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

t_token *expand(char *str, t_env *env, int flag)
{
	int i;
	t_token *head;
	char **strs;

	i = -1;
	head = NULL;
	if (!flag)
		return(addtok(&head, ft_newtoken(WORD, expand_prime(str, env), 0, 0)), head);
	strs = ft_split(expand_prime(str, env), ' ');
	if (!*strs)
		return(addtok(&head, ft_newtoken(WORD, ft_strdup(""), 0, 0)), head);
	while (strs[++i])
		addtok(&head, ft_newtoken(WORD, strs[i], 0, 0));	
	return(head);
}
t_token *expand_down(char *str, t_env *env, int flag)
{
	int i;
	t_token *head;
	char **strs;

	i = -1;
	head = NULL;
	if (!flag)
		return(addtok(&head, ft_newtoken(WORD, expand_prime(str, env), 0, 0)), head);
	strs = ft_split(expand_prime(str, env), ' ');
	if (!*strs)
		return(addtok(&head, ft_newtoken(WORD, ft_strdup(""), 0, 0)), head);
	while (strs[++i])
		addtok(&head, ft_newtoken(WORD, strs[i], 0, 0));	
	return(head);
}