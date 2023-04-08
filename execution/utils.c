/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:27:00 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/08 11:34:16 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(int fds[2])
{
	close(fds[0]);
	close(fds[1]);
}

void wildcard_change(t_token **list)
{
	t_token *tmp;
	t_token *tmp2;

	tmp = (*list)->next;
	if (*list && (*list)->hdoc && ft_strchr((*list)->token, '*'))
	{
		(*list) = wildmatch((*list)->token);
		while ((*list)->next)
				(*list) = (*list)->next;
		(*list)->next = tmp;
		return ;
	}
	tmp2 = *list;
	while (tmp2)
	{
		tmp = tmp2->next;
		if (tmp2->next && tmp2->next->hdoc && ft_strchr(tmp2->next->token, '*'))
		{
			tmp2->next = wildmatch(tmp2->next->token);
			lasttok(tmp2->next)->next = tmp->next;
		}
		else
			tmp2 = tmp2->next;
	}
}

void expand_change(t_token **list, t_env *myenv)
{
	t_token *tmp;
	t_token *tmp2;

	tmp = (*list)->next;
	if ((*list) && (*list)->expand && ft_strchr((*list)->token, '$'))
	{
		(*list) = expand(((*list))->token, myenv);
		while ((*list)->next)
				(*list) = (*list)->next;
		(*list)->next = tmp;
		return ;
	}
	tmp2 = *list;
	while (tmp2)
	{
		tmp = tmp2->next;
		if (tmp2->next && tmp2->next->expand && ft_strchr(tmp2->next->token, '$'))
		{
			tmp2->next = expand(tmp2->next->token, myenv);
			(tmp->hdoc) && (tmp2->next->hdoc = 1); // expinding with wildcard
			lasttok(tmp2->next)->next = tmp->next;
		}
		else
			tmp2 = tmp2->next;
	}
}


