/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 04:27:20 by absaid            #+#    #+#             */
/*   Updated: 2023/04/11 08:58:12 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

t_token	*ft_newtoken(t_flag type, char *word, int flag, int hdoc)
{
	t_token	*token;

	token = gc(sizeof(t_token), 1, 0);
	token->token = word;
	token->type = type;
	token->next = NULL;
	token->prev = NULL;
	token->down = NULL;
	token->expand = false;
	token->hdoc = false;
	(flag) && (token->expand = true);
	(hdoc) && (token->hdoc = true);
	return (token);
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

t_token	*lasttok_down(t_token *lst)
{
	while (lst)
	{
		if (lst->down == NULL)
			break ;
		lst = lst->down;
	}
	return (lst);
}

int	size_token(t_token *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
