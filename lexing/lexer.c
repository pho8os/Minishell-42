/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:30:23 by absaid            #+#    #+#             */
/*   Updated: 2023/03/04 04:10:50 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

t_token	*newtok(int type, char *token)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof (t_token));
	if (!new)
		return (NULL);
	new->type = type;
	new->token = token;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_token	*lasttok(t_token *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	addtok(t_token **lst, t_token *new)
{
	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->prev = lasttok(*lst);
	lasttok(*lst)->next = new;
	new->next = NULL;
}

t_token *get_tokens(char *cmdl, int *i)
{
	if (cmdl[*i] == ' ')
		return(newtok(SPACE, ft_strdup(" ")));
	else if (cmdl[*i] == '$')
		return(newtok(DOLLAR, ft_strdup("$")));
	else if (cmdl[*i] == '|' && cmdl[*i + 1] != '|')
		return(newtok(TOKEN_PIPE, ft_strdup("|")));
	else if (cmdl[*i] == '<' && cmdl[*i + 1] != '<')
		return(newtok(TOKEN_REDIRECT_INPUT, ft_strdup("<")));
	else if (cmdl[*i] == '>' && cmdl[*i + 1] != '>')
		return(newtok(TOKEN_REDIRECT_OUTPUT ,ft_strdup(">")));
	else if (cmdl[*i] == '&' && cmdl[*i + 1] != '&')
		return(newtok(COMMERCE ,ft_strdup( "&")));	
	else if (cmdl[*i] == '&' && cmdl[*i + 1] == '&')
		return(*i += 1, newtok(TOKEN_AND ,ft_strdup( "&&")));
	else if (cmdl[*i] == '|' && cmdl[*i + 1] == '|')
		return(*i += 1, newtok(TOKEN_OR ,ft_strdup("||")));
	else if (cmdl[*i] == '<' && cmdl[*i + 1] == '<')
		return(*i += 1, newtok(TOKEN_HERE_DOC ,ft_strdup("<<")));
	else if (cmdl[*i] == '>' && cmdl[*i + 1] == '>')
		return(*i += 1, newtok(TOKEN_HERE_DOC ,ft_strdup(">>")));
	else
		return(newtok(NOT_EXPECT ,ft_strdup("???")));
}

void get_token_quote(t_token **head ,char *cmdl, int *i)
{
	int j;

	if (cmdl[*i] == '\'')
		addtok(head, newtok(SINGLEQ, ft_strdup("\'")));
	else if (cmdl[*i] == '\"')
		addtok(head, newtok(DOUBLEQ, ft_strdup("\"")));
	*i += 1;
	j = *i;
	while (cmdl[*i] != '\'' && cmdl[*i] != '\"' && cmdl[*i])
		*i += 1;
	// printf(" j == %d\n", j); //!!!
	// printf(" i == %d\n", *i); //!!!
	addtok(head, newtok(TOKEN_WORD, ft_substr((cmdl + j), 0, *i - j)));
	if (cmdl[*i] == '\'')
		addtok(head, newtok(SINGLEQ, ft_strdup("\'")));
	else if (cmdl[*i] == '\"')
		addtok(head, newtok(DOUBLEQ, ft_strdup("\"")));
}

t_token *lexer(char *cmdl)
{
	t_token *head;
	int	i;
	int j;
	char *word;
	
	word = NULL;
	head = NULL;
	i = -1;
	j = 0;
	while(cmdl[++i])
	{
		if (cmdl[i] == '\'' || cmdl[i] == '\"')
			get_token_quote(&head, cmdl, &i);
		else if (!ft_strchr("|<>&$ ", cmdl[i]))
			word = ft_strjoin_c(word, (cmdl + i));
		else if (ft_strchr("|<>&$ ", cmdl[i]) || !cmdl[i])
		{
			if (word)
				addtok(&head, newtok(TOKEN_WORD, word));
			word = NULL;
			addtok(&head, get_tokens(cmdl, &i));
		}
	}
	if (word)
		addtok(&head, newtok(TOKEN_WORD, word));
	return (head);
}