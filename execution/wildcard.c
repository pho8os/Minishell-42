/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:22:37 by absaid            #+#    #+#             */
/*   Updated: 2023/04/11 08:43:24 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	match_3(char *obj, char *pattern)
{
	char	**tok;
	int		i;
	char	*res;

	tok = ft_split(pattern, '*');
	i = 0;
	while (tok[i])
	{
		res = ft_strstr(obj, tok[i]);
		if (res)
		{
			obj += ft_strlen(tok[i]);
			i++;
		}
		else
			return (false);
	}
	return (true);
}

bool	match_2(char *obj, char *pattern)
{
	int	j;
	int	i;

	j = ft_strlen(obj) - 1;
	i = ft_strlen(pattern);
	while (--i >= 0 && pattern[i] != '*')
	{
		if (pattern[i] != obj[j])
			return (false);
		j--;
	}
	return (match_3(ft_substr(obj, 0, j + 1), ft_substr(pattern, 0, i + 1)));
}

bool	match(char *obj, char *pattern)
{
	int		i;
	char	*tok;
	int		len;

	i = 0;
	tok = NULL;
	if (pattern[0] == '*' && obj[0] == '.')
		return (false);
	if (*pattern != '*')
	{
		while (pattern[i] && pattern[i] != '*')
			i++;
		tok = ft_substr(pattern, 0, i);
		if (ft_memcmp(obj, tok, ft_strlen(tok)))
			return (false);
	}
	len = 0;
	(tok) && (len = ft_strlen(tok));
	return (match_2(obj + len, pattern + len));
}

t_token	*wildmatch(char *pattern)
{
	DIR				*dir;
	struct dirent	*obj;
	t_token			*lst;

	lst = NULL;
	dir = opendir(".");
	obj = readdir(dir);
	while (obj)
	{
		if (match(obj->d_name, pattern))
			addtok(&lst, ft_newtoken(0, ft_strdup(obj->d_name), 0, 0));
		obj = readdir(dir);
	}
	closedir(dir);
	if (!lst)
		addtok(&lst, ft_newtoken(0, pattern, 0, 0));
	return (lst);
}
