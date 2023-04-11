/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:28:56 by absaid            #+#    #+#             */
/*   Updated: 2023/04/11 08:41:53 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getv(char *str, t_env *env)
{
	while (env)
	{
		if (!ft_memcmp(env->variable, str, ft_strlen(env->variable) + 1)
			&& env->print != -2)
			return (str = env->value, str);
		env = env->next;
	}
	return (NULL);
}

char	*expand_prime(char *str, t_env *env)
{
	int		i;
	char	*s;
	char	*p;

	i = 0;
	s = NULL;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '$')
			p = handle_non_variable(str, &i);
		else
			p = handle_variable(str, env, &i);
		s = _strjoin(s, p);
	}
	return (s);
}

t_token	*expand(char *str, t_env *env, int flag)
{
	int		i;
	t_token	*head;
	char	**strs;

	i = -1;
	head = NULL;
	if (!flag)
		return (addtok(&head, ft_newtoken(WORD, expand_prime(str, env), 0, 0)),
			head);
	strs = split_wc(expand_prime(str, env));
	if (!*strs)
		return (addtok(&head, ft_newtoken(WORD, ft_strdup(""), 0, 0)), head);
	while (strs[++i])
		addtok(&head, ft_newtoken(WORD, strs[i], 0, 0));
	return (head);
}
