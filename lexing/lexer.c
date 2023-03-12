/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:30:23 by absaid            #+#    #+#             */
/*   Updated: 2023/03/12 04:12:53 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

int getflag(char c)
{
	char *str;
	int i;

	i = 0;
	str = "\"\'|<>&() ";
	while(str[++i])
		if(str[i] == c)
			break ;
	return(i);
}

t_token *get_tokens(char *cmdl, size_t *i)
{
	if (cmdl[*i] == '|' && cmdl[*i + 1] == '|')
		return(*i += 1, newtok(OR ,ft_strdup("||")));
	else if (cmdl[*i] == '&' && cmdl[*i + 1] == '&')
		return(*i += 1, newtok(AND ,ft_strdup( "&&")));
	else if (cmdl[*i] == '<' && cmdl[*i + 1] == '<')
		return(*i += 1, newtok(HEREDOC ,ft_strdup("<<")));
	else if (cmdl[*i] == '>' && cmdl[*i + 1] == '>')
		return(*i += 1, newtok(APPEND ,ft_strdup(">>")));
	else
		return(newtok(getflag(cmdl[*i]), ft_substr((cmdl + *i), 0, 1)));
}

void get_token_quote(t_token **head ,char *cmdl, size_t *i)
{
	int j;
	
	addtok(head, newtok(getflag(cmdl[*i]), ft_substr((cmdl + *i), 0, 1)));
	*i += 1;
	j = *i;
	while (cmdl[*i] != cmdl[j - 1] && cmdl[*i])
		*i += 1;
	if (*i - j)
		addtok(head, newtok(0, ft_substr((cmdl + j), 0, *i - j)));
	if ((cmdl[*i] == '\'' || cmdl[*i] == '\"') && cmdl[*i])
		addtok(head, newtok(getflag(cmdl[*i]), ft_substr((cmdl + *i), 0, 1)));
	// while (cmdl[*i] != '\'' && cmdl[*i] != '\"' && cmdl[*i])
	// 	*i += 1;
	// printf(" j == %d\n", j); //!!!
	// printf(" i get_to == %zu\n", *i); //!!!
}

t_token *lexer(char *cmdl)
{
	size_t i;
	char *word;
	t_token *token;
	
	word = NULL;
	token = NULL;
	i = -1;
	while(++i < ft_strlen(cmdl))
	{
			// printf(" i == %zu\n", i); //!!!
		if ((cmdl[i] == '\'' || cmdl[i] == '\"') && cmdl[i])
			get_token_quote(&token, cmdl, &i);
		else if (!ft_strchr("|()<>&$\'\" ", cmdl[i]) && cmdl[i])
		{
			while(!ft_strchr("|()<>&$\'\" ", cmdl[i]) && cmdl[i])
				word = ft_strjoin_c(word, (cmdl + i++));
			i--;
			addtok(&token, newtok(0, word));
			word = NULL;	
			// printf(" cmd == %s\n", word); //!!!
		}
		else if (ft_strchr("|()<>&$\'\" ", cmdl[i]) && cmdl[i])
			addtok(&token, get_tokens(cmdl, &i));
	}
	return (token);
}
