/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcrads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:22:37 by absaid            #+#    #+#             */
/*   Updated: 2023/04/07 07:57:10 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

t_wild *wildnew(char *ptr)
{
	t_wild *g;
	
	g = malloc(sizeof(t_wild));
	if(!g)
		return(NULL); 
	return(g->match = ptr , g->next = NULL, g);
}

void addwild(t_wild **lst, t_wild *new)
{
	t_wild	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

bool match_3(char *obj, char *pattern)
{

	char **tok = ft_split(pattern,'*');
	int i = 0;
	while(tok[i])
	{
		char *res = ft_strstr(obj,tok[i]);
		if(res)
		{
			obj += ft_strlen(tok[i]);
			i++; 
		}
		else
			return(false);
	}
	return(true);
}

bool match_2(char *obj, char *pattern)
{

	int j = ft_strlen(obj) - 1;
	int i = ft_strlen(pattern);
	while(--i >= 0 && pattern[i] != '*')
	{
		if(pattern[i] != obj[j])
			return false;
		j--;
	}
	return(match_3(ft_substr(obj, 0, j + 1),ft_substr(pattern, 0, i + 1)));
}

bool match(char *obj, char *pattern)
{
	int i = 0;
	char *tok = NULL;
	
	if(*pattern != '*')
	{
		while(pattern[i] && pattern[i] != '*')
			i++;
		tok = ft_substr(pattern, 0, i);
		if(ft_memcmp(obj, tok, ft_strlen(tok)))
			return false;
	} 
	int len = 0;
	(tok) && ( len = ft_strlen(tok));
	return (match_2(obj + len, pattern + len));
}

char *wildmatch(char *pattern)
{
	DIR	*dir;
	struct dirent *obj;
	t_wild *lst = NULL;

	dir = opendir(".");
	obj = readdir(dir);
	while(obj)
	{
		if(match(obj->d_name, pattern))
			addwild(&lst, wildnew(ft_strdup(obj->d_name)));
		obj = readdir(dir);
	}
	char *str;
	str = NULL;
	while (lst)
	{
		str = ft_strjoin_sp(str, lst->match, ' ');
		lst = lst->next;
	}
	
	return(str);
}