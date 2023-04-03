/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 04:12:21 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/30 22:14:50 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_token	*newtok(char *token, e_flag type, e_flag change)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof (t_token));
	if (!new)
		return (NULL);
	new->type = type;
	new->token = token;
	new->change = change;	
	new->down = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	lstsize_token(t_token *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->type == WORD)
			i++;
		lst = lst->next;
	}
	return (i);
}

int	size_down(t_token *lst)
{
	int f;
	int	i;

	i = 0;
	f = 1;
	while (lst)
	{
		(lst->type ==  SPACE || lst->type ==  TAB) && (f = 1);
		(lst->type == WORD && f) && (i++) && (f = 0);
		lst = lst->down;
	}
	return (i);
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

t_token	*lasttok_down(t_token *lst)
{
	while (lst)
	{
		if (lst->down == NULL)
			break ;
		// printf("==========> %s\n", lst->token);
		// (lst->type == WORD && f) && (f = 0 && (*i)++);
		// (lst->type ==  SPACE && lst->type ==  TAB) && (f = 1);
		lst = lst->down;
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

void	add_down(t_token **lst, t_token *new, int f)
{
	t_token *tmp;
	
	
	if (!f)
		return (addtok(lst, new));
	tmp = lasttok(*lst);
	lasttok_down(tmp)->down = new;
	new->down = NULL;
}

void	cleartok(t_token **lst)
{
	t_token	*tmp;
	t_token	*t;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		t = tmp;
		tmp = tmp->next;
		free(t->token);
		free(t);
	}
	*lst = NULL;
}

char *dup_c(char c)
{
	char *str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);	
}