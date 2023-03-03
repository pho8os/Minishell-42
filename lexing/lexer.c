/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:30:23 by absaid            #+#    #+#             */
/*   Updated: 2023/03/03 05:19:04 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"
t_token	*newtok(int type, char *token)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof (t_token));
	if (!node)
		return (NULL);
	node->type = type;
	node->token = token;
	node->next = NULL;
	return (node);
}

char *gettok(char *cmdl, int ind, int *i)
{
	int start = ind;
	int end = ind + 1;
	
	if(start)
		while(/*cmdl[start]* machi special && */ start >=0)
			start--;		
	while(cmdl[end] != *cmdl && cmdl[end])
		end++;
	if(!cmdl[end])
		write(2, "error", 5); // TODO : exit the process;
	while(cmdl[end] /*and machi special*/)
		end++;
	return(*i = end, ft_substr(cmdl, start, end - start));
}

t_token *test(char *cmdl, int ind, int *i)
{
	if (cmdl[ind] == '\'')
		return(newtok(SINGLEQ, gettok(cmdl, ind, i)));
	else if (cmdl[ind] == '|' && cmdl[ind + 1] != '|')
		return(newtok(TOKEN_PIPE, ft_strdup("|")));
	else if (cmdl[ind] == '<' && cmdl[ind + 1] != '<')
		return(newtok(TOKEN_REDIRECT_INPUT, ft_strdup("<")));
	else if (cmdl[ind] == '>' && cmdl[ind + 1] != '>')
		return(newtok(TOKEN_REDIRECT_OUTPUT ,ft_strdup(">")));
	else if (cmdl[ind] == '&' && cmdl[ind + 1] == '&')
		return(*i = ++ind, newtok(TOKEN_AND ,ft_strdup( "&&")));
	else if (cmdl[ind] == '|' && cmdl[ind + 1] == '|')
		return(*i = ++ind, newtok(TOKEN_OR ,ft_strdup("||")));
	else if (cmdl[ind] == '<' && cmdl[ind + 1] == '<')
		return(*i = ++ind, newtok(TOKEN_HERE_DOC ,ft_strdup("<<")));
	else if (cmdl[ind] == '>' && cmdl[ind + 1] == '>')
		return(*i = ++ind, newtok(TOKEN_HERE_DOC ,ft_strdup(">>")));
}

t_token *lexer(char *cmdline)
{
	t_token *head;
	int	i;
	
	i = -1;
	while(cmdline[++i])
	{
		ft_lstadd_back(&head, test(cmdline, i, &i));
	}
}