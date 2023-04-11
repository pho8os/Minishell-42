/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:27:00 by yettabaa          #+#    #+#             */
/*   Updated: 2023/04/11 08:38:56 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(int fds[2])
{
	close(fds[0]);
	close(fds[1]);
}

int	count_words(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			count++;
	return (count);
}

void	wildcard_change(t_token **list)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp2 = *list;
	tmp = *list;
	if (tmp2 && tmp2->hdoc && ft_strchr(tmp2->token, '*'))
	{
		tmp2 = wildmatch(tmp2->token);
		lasttok(tmp2)->next = tmp->next;
		*list = tmp2;
		return ;
	}
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

void	norme_xpand(t_token **list, t_env *env)
{
	t_token	*hold;
	t_token	*t;
	t_token	*t2;

	t2 = *list;
	t = *list;
	while (t2)
	{
		t = t2->next;
		if (t2->next && t2->next->expand && ft_strchr(t2->next->token, '$'))
		{
			if (!ft_memcmp(t2->token, "export", 7) || (!t2->next->hdoc))
				hold = expand(t2->next->token, env, 0);
			else
				hold = expand(t2->next->token, env, 1);
			(t2->next = hold);
			(t->hdoc) && (t2->next->hdoc = 1);
			(t->down) && (lasttok(t2->next)->down = t->down);
			lasttok(t2->next)->next = t->next;
		}
		else
			t2 = t2->next;
	}
}

void	expand_change(t_token **list, t_env *env)
{
	t_token	*t;
	t_token	*t2;

	t2 = *list;
	t = *list;
	if (t2 && t2->expand && ft_strchr(t2->token, '$'))
	{
		(!t2->hdoc) && (t2 = expand(t2->token, env, 0));
		(t2->hdoc) && (t2 = expand(t2->token, env, 1));
		(t->hdoc) && (t2->hdoc = 1);
		(t->down) && (lasttok(t2)->down = t->down);
		return (lasttok(t2)->next = t->next, *list = t2, free(NULL));
	}
	norme_xpand(list, env);
}
