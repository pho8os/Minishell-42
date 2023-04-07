/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:30:23 by absaid            #+#    #+#             */
/*   Updated: 2023/04/07 08:41:06 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"


char *getword(char *str, int *index)
{
	int i;
	int j;
	
	i = *index;
	j = i;
	while(str[i] && !ft_strchr("\"\'|<>&() \t", str[i]))
		i++;
	return(*index = i - 1, ft_substr(str, j, i - j));
}

char *getq(char *str, int *index, char c)
{
	int i;
	int j;
	
	i = *index;
	j = i;
	while(str[i] && str[i] != c)
		i++;
	if(!str[i])
		return(*index = i - 1, ft_substr(str, j, i - j));
	return(*index = i - 1, ft_substr(str, j, i - j));
}
int getflag(char c, int flag)
{
	char *str;
	int i;

	i = -1;
	str = "\"\'|<>()";
	while(str[++i])
		if(str[i] == c)
			break ;
	if (c == '&' && !flag)
		return(0);
	else if(c == '&' && flag)
		return (9);
	(flag) && (i += 7);
	return(i + 1);
}
int allspace(int i, char *c)
{
	while(c[i] && c[i] == ' ')
		i++;
	if(c[i])
		return 0;
	else 
		return 1;
}

t_token *tokenizer(char *c)
{
	int	i = -1;
	t_token *token = 0;
	t_token *down = 0;
	bool dq = false;
	bool sq = false;
	bool space = true;
	int x;
	int op = 0;
	int cp = 0;
	
	while(c[++i])
	{
		x = 0;
		if((sq && c[i] != '\'') || (dq && c[i] != '\"'))
		{
			if(space)
			{
				addtok(&token, ft_newtoken(WORD, getq(c, &i, c[i - 1]), (dq == true), 0));
				space = false;
			}
			else if(!space)
			{
				down = lasttok(token);
				while(down->down)
					down = down->down;
				down->down = ft_newtoken(WORD, getq(c, &i, c[i - 1]), (dq == true), 0);
			}
		}
		else if(ft_strchr("\"\'|<>&() \t", c[i]))
		{
			(c[i] == '\'') && (sq = !sq);
			(c[i] == '\"') && (dq = !dq);
			(ft_strchr("|<>&", c[i]) && c[i] == c[i + 1]) && (x = 1);
			(c[i] != '\'' && c[i] != '\"') && (space = true);
			(c[i] == '(') && (op += 1);
			(c[i] == ')') && (cp += 1);
			if(!allspace(i, c) && c[i] != '\'' && c[i] != '\"' && c[i] != ' ' && c[i] != '\t')
				addtok(&token, ft_newtoken(getflag(c[i], x), ft_substr(c, i, x + 1), 0, 0));
			if(c[i] == ' ' || c[i] == '\t')
			{
				while((c[i] == ' ' || c[i] == '\t') && c[i])
					i++;
				i--;
			}
			i+= x;
		}
		else if(!ft_strchr("\"\'|<>&() \t", c[i]) && (!dq || !sq))
		{
			if(space)
			{
				addtok(&token, ft_newtoken(WORD, getword(c, &i), 1, 1));
				space = false;
			}
			else if(!space)
			{
				down = lasttok(token);
				while(down->down)
					down = down->down;
				down->down = ft_newtoken(WORD, getword(c, &i), 1, 1);
			}
		}
	}
	if((sq || dq) || (op != cp))
		return(puts("Syntax : Quote or parantes"), NULL);
	addtok(&token, ft_newtoken(END, ft_strdup("newline"), 0, 0));
	return(token);
	
}