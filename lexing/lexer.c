/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:30:23 by absaid            #+#    #+#             */
/*   Updated: 2023/04/02 03:15:46 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int getflag(char c, int flag)
{
	int i;
	char *str;
	
	(flag) && (i = 10);
	(!flag) && (i = 0);
	str = "|&<>()\"\'\t ";
	while(str[i % 10])
		if(str[i++ % 10] == c)
			break ;
	return(i - 1);			
}

void get_token_quote(t_token **token ,char *cmdl, int *i, int *f)
{
	int j;
	char *word;
	e_flag change;

	change = NUL;
	add_down(token, newtok(dup_c(cmdl[*i]), getflag(cmdl[*i], 0), change), *f);
	*i += 1;
	j = *i;
	while (cmdl[*i] != cmdl[j - 1] && cmdl[*i])
		*i += 1;
	if (cmdl[*i] != cmdl[j - 1])
		return(cleartok(token), *i = ft_strlen(cmdl) +1, ft_putendl_fd("=== > mushkil f \'\"", 2));
	*f = 1;
	if (*i - j)
	{
		word = ft_substr((cmdl + j), 0, *i - j);
		(ft_strchr(word, '$') && cmdl[*i] != '\'') && (change = EXPD);
		add_down(token, newtok(word, WORD, change), *f);
	}
	add_down(token, newtok(dup_c(cmdl[*i]), getflag(cmdl[*i], 0), change), *f);
}

t_token *get_tokens(char *cmdl, int *i)
{
	t_token *tok;

	if (cmdl[*i + 1] && cmdl[*i] == cmdl[*i + 1] && ft_strchr("|&<>", cmdl[*i]))
		return(*i += 1, newtok(ft_substr((cmdl + *i - 1), 0, 2), getflag(cmdl[*i - 1], 1), NUL));
	if (!(*i == 0 && (cmdl[*i] == ' ' || cmdl[*i] == '\t')))
		tok = newtok(dup_c(cmdl[*i]), getflag(cmdl[*i], 0), NUL);
	if (ft_strchr("\t ", cmdl[*i]))
	{
		while (ft_strchr("\t ", cmdl[*i]) && cmdl[*i])
			*i += 1;
		*i -= 1;	
	}
	return(tok);
}

void tokening(t_token **token ,char *cmdl, int *i, int *f)
{
	char *word;
	e_flag chg;

	chg = NUL;
	word = NULL;
	if (ft_strchr("|&<>()\"\'\t ", cmdl[*i]) && cmdl[*i]) 
	{
		if (*f && ft_strchr("<>\t ", cmdl[*i]))
			return (add_down(token, get_tokens(cmdl, i), *f));
		else if ((!*f && ft_strchr(" \t", cmdl[*i])))
			return ;
		return (*f = 0, addtok(token, get_tokens(cmdl, i)));
	}
	while(!ft_strchr("|&<>()\"\'\t ", cmdl[*i]) && cmdl[*i])
		word = ft_strjoin_c(word, (cmdl + (*i)++));
	(*i)--;
	(ft_strchr(word, '$')) && (chg = EXPD);
	(ft_strchr(word, '*')) && (chg = WILD);
	(ft_strchr(word, '$') && ft_strchr(word, '*')) && (chg = BOTH);
	add_down(token, newtok(word, WORD, chg), *f);
	*f = 1;
}

t_token *lexer(char *cmdl)
{
	int f;
	int i;
	t_token *token;
	
	f = 0;
	i = -1;
	token = NULL;
	while(++i < ft_strlen(cmdl))
	{
		// printf(" c == %c\n", cmdl[i]); //!!!
		if ((cmdl[i] == '\'' || cmdl[i] == '\"') && cmdl[i])
			get_token_quote(&token, cmdl, &i, &f);
		else
			tokening(&token, cmdl, &i, &f);
	}
	addtok(&token, newtok(NULL, END, NUL));
	return (token);
}
