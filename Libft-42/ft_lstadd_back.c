/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:24:58 by absaid            #+#    #+#             */
/*   Updated: 2023/03/15 22:19:56 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	addbenv(t_env **lst, t_env *new)
{
	t_env	*tmp;
	
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}

void	addexport(t_env **lst, t_env *new)
{
	int len;
	t_env	*tmp;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	len = ft_strlen(new->variable) + 1;
	while (tmp)
	{
		if (ft_memcmp((tmp)->variable, new->variable, len) >= 0)
		{
			new->prev = tmp->prev;
			new->next = tmp;
			tmp->prev = new;
			if (!new->prev)
				*lst = new;
			return ;
		}
		tmp = tmp->next;
	}
	addbenv(lst, new);
}
